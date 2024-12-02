// Fill out your copyright notice in the Description page of Project Settings.

#include "RpcCommunicator.h"

void URpcCommunicator::PostInitProperties()
{
	Super::PostInitProperties();
	bIsOpen = false;
	CurrentUnrealRlOutput = MakeUnique<communicator_objects::UnrealRLOutputProto>();
}

bool URpcCommunicator::Initialize(const FCommunicatorInitParameters& InitParameters, FUnrealRLInitParameters& InitParametersOut)
{
	communicator_objects::UnrealRLInitializationOutputProto AcademyParameters;
	AcademyParameters.set_name(TCHAR_TO_UTF8(*InitParameters.Name));
	AcademyParameters.set_package_version(TCHAR_TO_UTF8(*InitParameters.UnrealPackageVersion));
	AcademyParameters.set_communication_version(TCHAR_TO_UTF8(*InitParameters.UnrealCommunicationVersion));

	communicator_objects::UnrealInputProto Input;
	communicator_objects::UnrealInputProto InitializationInput;

	try
	{
		// Create UnrealOutputProto and set the RLInitializationOutput
		communicator_objects::UnrealOutputProto UnrealOutput;
		*UnrealOutput.mutable_rl_initialization_output() = AcademyParameters;

		InitializationInput = Initialize(
			InitParameters.Port,
			UnrealOutput,
			Input);
	}
	catch (const std::exception& ex)
	{
		UE_LOG(LogTemp, Error, TEXT("Unexpected exception when trying to initialize communication: %s"), UTF8_TO_TCHAR(ex.what()));
		InitParametersOut = FUnrealRLInitParameters();
		NotifyQuitAndShutDownChannel();
		return false;
	}

	FString PythonPackageVersion = UTF8_TO_TCHAR(InitializationInput.rl_initialization_input().package_version().c_str());
	FString PythonCommunicationVersion = UTF8_TO_TCHAR(InitializationInput.rl_initialization_input().communication_version().c_str());

	bool CommunicationIsCompatible = CheckCommunicationVersionAreCompatible(
		InitParameters.UnrealCommunicationVersion,
		PythonCommunicationVersion);

	// Initialization succeeded part-way. The most likely cause is a mismatch between the communicator API strings.
	if (InitializationInput.has_rl_initialization_input() && !Input.has_rl_input())
	{
		if (!CommunicationIsCompatible)
		{
			UE_LOG(LogTemp, Warning, TEXT("Communication protocol between python (%s) and Unreal (%s) have different versions which make them incompatible. Python library version: %s."),
				*PythonCommunicationVersion, *InitParameters.UnrealCommunicationVersion, *PythonPackageVersion);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Unknown communication error between Python. Python communication protocol: %s, Python library version: %s."),
				*PythonCommunicationVersion, *PythonPackageVersion);
		}

		InitParametersOut = FUnrealRLInitParameters();
		return false;
	}

	// UpdateEnvironmentWithInput(Input.rlinitializationinput()); // Implement this if needed
	SendCommandEvent(Input.rl_input().command());
	InitParametersOut.Seed = InitializationInput.rl_initialization_input().seed();
	InitParametersOut.NumAreas = InitializationInput.rl_initialization_input().num_areas();
	InitParametersOut.PythonLibraryVersion = UTF8_TO_TCHAR(InitializationInput.rl_initialization_input().package_version().c_str());
	InitParametersOut.PythonCommunicationVersion = UTF8_TO_TCHAR(InitializationInput.rl_initialization_input().communication_version().c_str());

	// Be sure to shut down the grpc channel when the application is quitting.
	FCoreDelegates::OnPreExit.AddUObject(this, &URpcCommunicator::NotifyQuitAndShutDownChannel);

	return true;
}

bool URpcCommunicator::EstablishConnection(int32 Port)
{
	std::string ServerAddress = "localhost:" + std::to_string(Port);
	Channel = grpc::CreateChannel(ServerAddress, grpc::InsecureChannelCredentials());
	Stub = communicator_objects::UnrealToExternalProto::NewStub(Channel);
	return Channel != nullptr && Stub != nullptr;
}

bool URpcCommunicator::SendAndReceiveMessage(const communicator_objects::UnrealMessageProto& Request, communicator_objects::UnrealMessageProto& Response)
{
	grpc::ClientContext Context;
	grpc::Status		Status = Stub->Exchange(&Context, Request, &Response);

	if (!Status.ok())
	{
		bIsOpen = false;
		NotifyQuitAndShutDownChannel();
		throw std::runtime_error(Status.error_message());
	}

	return Response.header().status() == 200;
}

communicator_objects::UnrealInputProto URpcCommunicator::Initialize(int32 Port, const communicator_objects::UnrealOutputProto& UnrealOutput, communicator_objects::UnrealInputProto& UnrealInput)
{
	bIsOpen = true;

	if (!EstablishConnection(Port))
	{
		throw std::runtime_error("Failed to establish connection");
	}

	communicator_objects::UnrealMessageProto Result;
	communicator_objects::UnrealMessageProto InputMessage;

	if (!SendAndReceiveMessage(WrapMessage(&UnrealOutput, 200), Result))
	{
		throw std::runtime_error("Failed to receive proper response");
	}

	if (!SendAndReceiveMessage(WrapMessage(nullptr, 200), InputMessage))
	{
		throw std::runtime_error("Failed to receive input message");
	}

	UnrealInput = InputMessage.unreal_input();

	if (Result.header().status() != 200 || InputMessage.header().status() != 200)
	{
		bIsOpen = false;
		NotifyQuitAndShutDownChannel();
	}

	return Result.unreal_input();
}

communicator_objects::UnrealMessageProto URpcCommunicator::WrapMessage(const communicator_objects::UnrealOutputProto* Content, int32 Status)
{
	communicator_objects::UnrealMessageProto Message;
	auto*									 Header = Message.mutable_header();
	Header->set_status(Status);
	if (Content != nullptr)
	{
		*Message.mutable_unreal_output() = *Content;
	}
	return Message;
}

bool URpcCommunicator::CheckCommunicationVersionAreCompatible(const FString& UnrealCommunicationVersion, const FString& PythonApiVersion)
{
	TArray<FString> UnrealParts;
	UnrealCommunicationVersion.ParseIntoArray(UnrealParts, TEXT("."));
	int32 UnrealMajor = FCString::Atoi(*UnrealParts[0]);
	int32 UnrealMinor = UnrealParts.Num() > 1 ? FCString::Atoi(*UnrealParts[1]) : 0;

	TArray<FString> PythonParts;
	PythonApiVersion.ParseIntoArray(PythonParts, TEXT("."));
	int32 PythonMajor = FCString::Atoi(*PythonParts[0]);
	int32 PythonMinor = PythonParts.Num() > 1 ? FCString::Atoi(*PythonParts[1]) : 0;

	if (UnrealMajor == 0)
	{
		if (UnrealMajor != PythonMajor || UnrealMinor != PythonMinor)
		{
			return false;
		}
	}
	else if (UnrealMajor != PythonMajor)
	{
		return false;
	}
	else if (UnrealMinor != PythonMinor)
	{
		// If a feature is used in Unreal but not supported in the trainer,
		// we will warn at the point it's used. Don't warn here to avoid noise.
	}

	return true;
}

void URpcCommunicator::NotifyQuitAndShutDownChannel()
{
	QuitCommandReceived.Broadcast();
	try
	{	
		Channel.reset();
	}
	catch (...)
	{
		// Catch all exceptions
	}
}

FQuitCommandHandler& URpcCommunicator::OnQuitCommandReceived()
{
	return QuitCommandReceived;
}

FResetCommandHandler& URpcCommunicator::OnResetCommandReceived()
{
	return ResetCommandReceived;
}

FRLInputReceivedHandler& URpcCommunicator::OnRLInputReceived()
{
	return RLInputReceived;
}

void URpcCommunicator::SubscribeBrain(const FString& Name, FActionSpec ActionSpec)
{
	if (BehaviorNames.Contains(Name))
	{
		return;
	}
	BehaviorNames.Add(Name);
	CurrentUnrealRlOutput->mutable_agentinfos()->insert(
		std::make_pair(std::string(TCHAR_TO_UTF8(*Name)), communicator_objects::UnrealRLOutputProto_ListAgentInfoProto()));
	CacheActionSpec(Name, ActionSpec);
}

void URpcCommunicator::CacheActionSpec(const FString& Name, FActionSpec ActionSpec)
{
	if (SentBrainKeys.Contains(Name))
	{
		return;
	}
	UnsentBrainKeys.Emplace(Name, ActionSpec);
}

void URpcCommunicator::PutObservations(const FString& BehaviorName, const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors)
{
	communicator_objects::AgentInfoProto AgentInfoProto = ToAgentInfoProto(Info);
	for (auto& sensor : Sensors)
	{
		communicator_objects::ObservationProto ObsProto = GetObservationProto(sensor, ObsWriter);
		*AgentInfoProto.add_observations() = ObsProto;
	}

	auto& agentInfosMap = *CurrentUnrealRlOutput->mutable_agentinfos();
	*agentInfosMap[TCHAR_TO_UTF8(*BehaviorName)].add_value() = AgentInfoProto;

	bNeedCommunicateThisStep = true;
	if (!OrderedAgentsRequestingDecisions.Contains(BehaviorName))
	{
		TArray<int> IntArray;
		OrderedAgentsRequestingDecisions.Add(BehaviorName, IntArray);
	}
	if (!Info.bDone)
	{
		OrderedAgentsRequestingDecisions[BehaviorName].Add(Info.EpisodeId);
	}
	if (!LastActionsReceived.Contains(BehaviorName))
	{
		TMap<int32, FActionBuffers> DictActionReceived;
		LastActionsReceived.Add(BehaviorName, DictActionReceived);
	}
	LastActionsReceived[BehaviorName].Add(Info.EpisodeId, FActionBuffers::Empty);
	if (Info.bDone)
	{
		LastActionsReceived[BehaviorName].Remove(Info.EpisodeId);
	}
}

void URpcCommunicator::DecideBatch()
{
	if (!bNeedCommunicateThisStep)
	{
		return;
	}
	bNeedCommunicateThisStep = false;
	SendBatchedMessageHelper();
}

const FActionBuffers URpcCommunicator::GetActions(const FString& Key, int32 AgentId)
{
	if (LastActionsReceived.Contains(Key))
	{
		if (LastActionsReceived[Key].Contains(AgentId))
		{
			return LastActionsReceived[Key][AgentId];
		}
	}
	return FActionBuffers::Empty;
}

void URpcCommunicator::SendBatchedMessageHelper()
{
	communicator_objects::UnrealOutputProto Message;
	Message.mutable_rl_output()->CopyFrom(*CurrentUnrealRlOutput);

	TSharedPtr<communicator_objects::UnrealRLInitializationOutputProto> tempUnityRlInitializationOutput = GetTempUnrealRlInitializationOutput();
	if (tempUnityRlInitializationOutput != nullptr)
	{
		*Message.mutable_rl_initialization_output() = *tempUnityRlInitializationOutput.Get();
	}

	communicator_objects::UnrealInputProto Input = Exchange(&Message);
	UpdateSentActionSpec(tempUnityRlInitializationOutput.Get());

	// Iterate through the agentInfos map
	for (auto& agentInfoPair : *CurrentUnrealRlOutput->mutable_agentinfos())
	{
		// Clear the repeated field `value` in ListAgentInfoProto
		agentInfoPair.second.mutable_value()->Clear();
	}

	// Get the RlInput field
	const communicator_objects::UnrealRLInputProto& RlInput = Input.rl_input();

	// Check if AgentActions is present and not empty
	if (RlInput.agent_actions().empty())
	{
		return;
	}

	SendCommandEvent(RlInput.command());

	for (const auto& brainName : RlInput.agent_actions())
	{
		const FString& Key = brainName.first.c_str();
		if (OrderedAgentsRequestingDecisions.Find(Key)->IsEmpty())
		{
			continue;
		}

		if (brainName.second.value().empty())
		{
			continue;
		}

		const auto& agentActions = ToAgentActionList(brainName.second);
		int			numAgents = OrderedAgentsRequestingDecisions.Find(Key)->Num();
		for (int i = 0; i < numAgents; ++i)
		{
			const auto& agentAction = agentActions[i];
			int			agentId = (*OrderedAgentsRequestingDecisions.Find(Key))[i];
			if (LastActionsReceived.Find(Key)->Contains(agentId))
			{
				LastActionsReceived[Key].Add(agentId, agentAction);
			}
		}
	}

	for (TPair<FString, TArray<int32>>& Pair : OrderedAgentsRequestingDecisions)
	{
		Pair.Value.Empty();
	}
}

communicator_objects::ObservationProto URpcCommunicator::GetObservationProto(TScriptInterface<IISensor> Sensor, ObservationWriter& ObservationWriter)
{

	FObservationSpec								  ObsSpec = Sensor->GetObservationSpec();
	FInplaceArray<int32>							  Shape = ObsSpec.GetShape();
	int												  NumFloats = USensorExtensions::ObservationSize(Sensor);
	communicator_objects::ObservationProto::FloatData FloatDataProto;

	// Resize the float array
	for (int i = 0; i < NumFloats; ++i)
	{
		FloatDataProto.add_data(0.0f);
	}

	// Assume observationWriter is an instance of a class that has SetTarget() method
	ObservationWriter.SetTarget(FloatDataProto.mutable_data(), Sensor->GetObservationSpec().GetShape(), 0);
	Sensor->Write(ObservationWriter);

	communicator_objects::ObservationProto ObservationProto;
	*ObservationProto.mutable_float_data() = FloatDataProto;

	// Add the dimension properties to the observationProto
	FInplaceArray<EDimensionProperty> DimensionProperties = ObsSpec.GetDimensionProperties();
	for (int i = 0; i < Shape.GetLength(); i++)
	{
		ObservationProto.mutable_dimension_properties()->Add((int)DimensionProperties[i]);
	}

	for (int i = 0; i < Shape.GetLength(); i++)
	{
		ObservationProto.mutable_shape()->Add(Shape[i]);
	}

	FString SensorName = Sensor->GetName();
	if (!SensorName.IsEmpty())
	{
		ObservationProto.set_name(TCHAR_TO_UTF8(*SensorName));
	}
	return ObservationProto;
}

communicator_objects::UnrealInputProto URpcCommunicator::Exchange(const communicator_objects::UnrealOutputProto* UnrealOutput)
{

	if (!bIsOpen)
	{
		return communicator_objects::UnrealInputProto();
	}

	try
	{

		communicator_objects::UnrealMessageProto InputMessage;
		if (!SendAndReceiveMessage(WrapMessage(UnrealOutput, 200), InputMessage))
		{
			throw std::runtime_error("Failed to receive input message");
		}

		return InputMessage.unreal_input();
	}
	catch (const std::exception& Ex)
	{
		// Fall-through for other error types
		UE_LOG(LogTemp, Error, TEXT("Communication Exception: %s. Disconnecting from trainer."), *FString(Ex.what()));
	}

	bIsOpen = false;
	NotifyQuitAndShutDownChannel();
	return communicator_objects::UnrealInputProto();
}

TSharedPtr<communicator_objects::UnrealRLInitializationOutputProto> URpcCommunicator::GetTempUnrealRlInitializationOutput()
{
	TSharedPtr<communicator_objects::UnrealRLInitializationOutputProto> Output = nullptr;
	for (const auto& Elem : UnsentBrainKeys)
	{

		FString			   BehaviorName = Elem.Key;
		const FActionSpec& ActionSpec = Elem.Value;

		if (CurrentUnrealRlOutput->agentinfos().contains(TCHAR_TO_UTF8(*BehaviorName)))
		{

			if (CurrentUnrealRlOutput->agentinfos().at(TCHAR_TO_UTF8(*BehaviorName)).value_size() > 0)
			{
				if (!Output.IsValid())
				{ // TUniquePtr uses IsValid() to check for nullptr
					Output = MakeShared<communicator_objects::UnrealRLInitializationOutputProto>();
				}
				Output->mutable_brain_parameters()->Add(ToBrainParametersProto(ActionSpec, BehaviorName, true));
			}
		}
	}
	return Output;
}

communicator_objects::BrainParametersProto URpcCommunicator::ToBrainParametersProto(const FActionSpec& ActionSpec, FString Name, bool bIsTraining)
{
	communicator_objects::BrainParametersProto BrainParametersProto;
	BrainParametersProto.set_brain_name(TCHAR_TO_UTF8(*Name));
	BrainParametersProto.set_is_training(bIsTraining);
	*BrainParametersProto.mutable_action_spec() = ToActionSpecProto(ActionSpec);
	return BrainParametersProto;
}

communicator_objects::ActionSpecProto URpcCommunicator::ToActionSpecProto(const FActionSpec& ActionSpec)
{
	communicator_objects::ActionSpecProto ActionSpecProto;
	ActionSpecProto.set_num_continuous_actions(ActionSpec.NumContinuousActions);
	ActionSpecProto.set_num_discrete_actions(ActionSpec.GetNumDiscreteActions());
	if (ActionSpec.BranchSizes.Num() != 0)
	{
		for (auto BranchSize : ActionSpec.BranchSizes)
		{
			ActionSpecProto.mutable_discrete_branch_sizes()->Add(BranchSize);
		}
	}
	return ActionSpecProto;
}

void URpcCommunicator::UpdateSentActionSpec(const communicator_objects::UnrealRLInitializationOutputProto* Output)
{

	// Check if Output is not null
	if (Output == nullptr)
	{
		return;
	}

	// Iterate through BrainParameters in the output
	for (int32 i = 0; i < Output->brain_parameters_size(); ++i)
	{
		const communicator_objects::BrainParametersProto& BrainProto = Output->brain_parameters(i);
		FString											  BrainName = UTF8_TO_TCHAR(BrainProto.brain_name().c_str());

		// Add the brain name to the sent brain keys
		SentBrainKeys.Add(BrainName);

		// Remove the brain name from the unsent brain keys
		UnsentBrainKeys.Remove(BrainName);
	}
}

void URpcCommunicator::SendCommandEvent(communicator_objects::CommandProto Command)
{
	switch (Command)
	{
		case communicator_objects::RESET:
		{
			for (auto& Elem : OrderedAgentsRequestingDecisions)
			{
				Elem.Value.Empty(); // Clears the TArray
			}
			if (ResetCommandReceived.IsBound())
			{
				ResetCommandReceived.Broadcast();
			}
			return;
		}
		case communicator_objects::QUIT:
		{
			NotifyQuitAndShutDownChannel();
			return;
		}
		default:
			return;
	}
}

TArray<FActionBuffers> URpcCommunicator::ToAgentActionList(const communicator_objects::UnrealRLInputProto_ListAgentActionProto Proto)
{
	TArray<FActionBuffers> AgentActions;
	AgentActions.Reserve(Proto.value_size());

	for (const auto& Ap : Proto.value())
	{
		AgentActions.Add(ToActionBuffers(Ap));
	}

	return AgentActions;
}

FActionBuffers URpcCommunicator::ToActionBuffers(const communicator_objects::AgentActionProto& Proto)
{
	// Convert the continuous actions from Proto
	TSharedPtr<TArray<float>> ContinuousActions = MakeShared<TArray<float>>();
	for (int i = 0; i < Proto.continuous_actions_size(); ++i)
	{
		ContinuousActions->Add(Proto.continuous_actions(i));
	}

	// Convert the discrete actions from Proto
	TSharedPtr<TArray<int32>> DiscreteActions = MakeShared<TArray<int32>>();
	for (int i = 0; i < Proto.discrete_actions_size(); ++i)
	{
		DiscreteActions->Add(Proto.discrete_actions(i));
	}

	return FActionBuffers(ContinuousActions, DiscreteActions);
}

communicator_objects::AgentInfoProto URpcCommunicator::ToAgentInfoProto(const FAgentInfo& Info)
{
	communicator_objects::AgentInfoProto AgentInfoProto;
	AgentInfoProto.set_reward(Info.Reward);
	AgentInfoProto.set_group_reward(Info.GroupReward);
	AgentInfoProto.set_max_step_reached(Info.bMaxStepReached);
	AgentInfoProto.set_done(Info.bDone);
	AgentInfoProto.set_id(Info.EpisodeId);
	AgentInfoProto.set_group_id(Info.GroupId);

	if (Info.DiscreteActionMasks.Num() != 0)
	{
		for (bool MaskValue : Info.DiscreteActionMasks)
		{
			AgentInfoProto.mutable_action_mask()->Add(MaskValue);
		}
	}
	return AgentInfoProto;
}

void URpcCommunicator::Dispose()
{
	if (!bIsOpen)
	{
		return;
	}
	try
	{
		// Assuming Stub is initialized and WrapMessage returns a valid object
		communicator_objects::UnrealMessageProto Response;
		grpc::ClientContext						 Context;
		grpc::Status							 Status = Stub->Exchange(&Context, WrapMessage(nullptr, 400), &Response);
		bIsOpen = false;
	}
	catch (...)
	{
		// Catch all exceptions
	}
}
