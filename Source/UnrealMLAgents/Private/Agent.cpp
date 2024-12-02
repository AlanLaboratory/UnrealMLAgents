// Fill out your copyright notice in the Description page of Project Settings.

#include "Agent.h"
#include "Academy.h"
#include "ISensor.h"
#include "VectorSensor.h"
#include "SensorComponent.h"
#include "EpisodeIdCounter.h"
#include "ActuatorComponent.h"
#include "BehaviorParameters.h"
#include "GameFramework/Actor.h"

EBuiltInActuatorType UAgentVectorActuator::GetBuiltInActuatorType() const
{
	return EBuiltInActuatorType::AgentVectorActuator;
}

// Called when the game starts
void UAgent::BeginPlay()
{
	Super::BeginPlay();
	Initialize();
	LazyInitialize();
}

// Called every frame
void UAgent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAgent::LazyInitialize()
{
	if (bInitialized)
	{
		return;
	}
	bInitialized = true;

	// Grab the "static" properties for the Agent.
	EpisodeId = EpisodeIdCounter::GetEpisodeId();
	PolicyFactory = GetOwner()->FindComponentByClass<UBehaviorParameters>();

	Info = FAgentInfo();
	Sensors = TArray<TScriptInterface<IISensor>>();

	UAcademy* Academy = UAcademy::GetInstance();
	Academy->OnAgentIncrementStep.AddDynamic(this, &UAgent::AgentIncrementStep);
	Academy->OnAgentSendState.AddDynamic(this, &UAgent::SendInfo);
	Academy->OnDecideAction.AddDynamic(this, &UAgent::DecideAction);
	Academy->OnAgentAct.AddDynamic(this, &UAgent::AgentStep);
	Academy->OnAgentForceReset.AddDynamic(this, &UAgent::AgentReset);

	InitializeActuators();

	// Placeholder for generating policy
	Brain = PolicyFactory->GeneratePolicy(ActuatorManager->GetCombinedActionSpec(), ActuatorManager);

	ResetData();
	Initialize();
	InitializeSensors();

	// Initialize continuous actions with zeros
	TSharedPtr<TArray<int32>> DiscreteActionArray = MakeShared<TArray<int32>>();
	DiscreteActionArray->Init(0, ActuatorManager->GetNumDiscreteActions());

	// Initialize discrete actions with zeros
	TSharedPtr<TArray<float>> ContinuousActionArray = MakeShared<TArray<float>>();
	ContinuousActionArray->Init(0.0f, ActuatorManager->GetNumContinuousActions());

	// Set storedActions in AgentInfo
	Info.StoredActions = FActionBuffers(
		ContinuousActionArray,
		DiscreteActionArray);

	Info.GroupId = GroupId;

	if (Academy->TotalStepCount != 0)
	{
		OnEpisodeBegin();
	}
}

void UAgent::NotifyAgentDone(EDoneReason DoneReason)
{
	if (Info.bDone)
	{
		return;
	}
	Info.EpisodeId = EpisodeId;
	Info.Reward = Reward;
	Info.GroupReward = GroupReward;
	Info.bDone = true;
	Info.bMaxStepReached = DoneReason == EDoneReason::MaxStepReached;
	Info.GroupId = GroupId;
	UpdateSensors();

	// TODO CollectObservationChecker
	CollectObservations(CollectObservationsSensor);

	// Request the last decision with no callbacks
	// We request a decision so Python knows the Agent is done immediately
	if (Brain)
	{
		Brain->RequestDecision(Info, Sensors);
	}

	ResetSensors();

	if (DoneReason != EDoneReason::Disabled)
	{
		CompletedEpisodes++;
	}

	Reward = 0.0;
	GroupReward = 0.0;
	CumulativeReward = 0.0;
	bRequestAction = false;
	bRequestDecision = false;
	Info.StoredActions.Clear();
}

void UAgent::ReloadPolicy()
{
	if (!bInitialized)
	{
		return;
	}
	Brain = TScriptInterface<IIPolicy>(PolicyFactory->GeneratePolicy(ActuatorManager->GetCombinedActionSpec(), ActuatorManager));
}

void UAgent::InitializeActuators()
{
	TArray<UActuatorComponent*> AttachedActuators;
	if (PolicyFactory->bUseChildActuators)
	{
		GetAllChildComponents<UActuatorComponent>(AttachedActuators);
	}
	else
	{
		GetOwner()->GetComponents<UActuatorComponent>(AttachedActuators);
	}

	FActionSpec ActionSpec = PolicyFactory->BrainParameters.ActionSpec;
	VectorActuator = NewObject<UAgentVectorActuator>(this);
	if (VectorActuator)
	{
		VectorActuator->Initialize(this, this, ActionSpec);
	}

	ActuatorManager = NewObject<UActuatorManager>();
	ActuatorManager->Initialize(AttachedActuators.Num() + 1);
	ActuatorManager->Add(VectorActuator);

	for (UActuatorComponent* Component : AttachedActuators)
	{
		ActuatorManager->Add(Component);
	}
}

void UAgent::InitializeSensors()
{
	if (PolicyFactory == nullptr)
	{
		PolicyFactory = GetOwner()->GetComponentByClass<UBehaviorParameters>();
	}

	TArray<USensorComponent*> AttachedSensorComponents;

	if (PolicyFactory->bUseChildSensors)
	{
		GetAllChildComponents<USensorComponent>(AttachedSensorComponents);
	}
	else
	{
		GetOwner()->GetComponents<USensorComponent>(AttachedSensorComponents);
	}

	Sensors.Reserve(Sensors.Num() + AttachedSensorComponents.Num());
	for (USensorComponent* Component : AttachedSensorComponents)
	{
		TArray<TScriptInterface<IISensor>> CreatedSensors = Component->CreateSensors();
		Sensors.Append(CreatedSensors);
	}

	FBrainParameters param = PolicyFactory->BrainParameters;
	if (param.VectorObservationSize > 0)
	{
		CollectObservationsSensor = NewObject<UVectorSensor>(this);
		CollectObservationsSensor->Initialize(param.VectorObservationSize);
		Sensors.Add(CollectObservationsSensor);
	}

	USensorUtils::SortSensors(Sensors);
}

void UAgent::CleanupSensors()
{
	for (int32 i = 0; i < Sensors.Num(); i++)
	{
		if (Sensors[i])
		{
			Sensors[i] = nullptr;
		}
	}
}

void UAgent::UpdateSensors()
{
	for (int32 i = 0; i < Sensors.Num(); i++)
	{
		if (!bStopUpdateObservation)
		{
			Sensors[i]->Update();
		}
	}
}

void UAgent::ResetSensors()
{
	for (int32 i = 0; i < Sensors.Num(); i++)
	{
		Sensors[i]->Reset();
	}
}

void UAgent::SendInfoToBrain()
{

	if (!bInitialized)
	{
		UE_LOG(LogTemp, Error, TEXT("Call to SendInfoToBrain when Agent hasn't been initialized. Please ensure that you are calling 'Super::OnEnable()' if you have overridden OnEnable."));
		return;
	}

	if (Brain == nullptr)
	{
		return;
	}

	if (Info.bDone)
	{
		Info.ClearActions();
	}
	else
	{
		Info.CopyActions(ActuatorManager->GetStoredActions());
	}

	UpdateSensors();

	CollectObservations(CollectObservationsSensor);
	ActuatorManager->WriteActionMask();

	if (IsValid(&ActuatorManager->GetDiscreteActionMask()))
	{
		Info.DiscreteActionMasks = ActuatorManager->GetDiscreteActionMask().GetMask();
	}
	else
	{
		Info.DiscreteActionMasks.Empty();
	}

	Info.Reward = Reward;
	Info.GroupReward = GroupReward;
	Info.bDone = false;
	Info.bMaxStepReached = false;
	Info.EpisodeId = EpisodeId;
	Info.GroupId = GroupId;

	Brain->RequestDecision(Info, Sensors);
}

void UAgent::ResetData()
{
	if (ActuatorManager)
	{
		ActuatorManager->ResetData();
	}
}

void UAgent::SetReward(float NewReward)
{
	CumulativeReward += (NewReward - Reward);
	Reward = NewReward;
}

void UAgent::AddReward(float Increment)
{
	Reward += Increment;
	CumulativeReward += Increment;
}

void UAgent::SetGroupReward(float NewReward)
{
	GroupReward = NewReward;
}

void UAgent::AddGroupReward(float Increment)
{
	GroupReward += Increment;
}

void UAgent::EndEpisode()
{
	EndEpisodeAndReset(EDoneReason::DoneCalled);
}

void UAgent::EpisodeInterrupted()
{
	EndEpisodeAndReset(EDoneReason::MaxStepReached);
}

void UAgent::EndEpisodeAndReset(EDoneReason Reason)
{
	NotifyAgentDone(Reason);
	AgentReset();
}

void UAgent::RequestDecision()
{
	bRequestDecision = true;
	RequestAction();
}

void UAgent::RequestAction()
{
	bRequestAction = true;
}

FActionBuffers UAgent::GetStoredActionBuffers()
{
	return ActuatorManager->GetStoredActions();
}

void UAgent::AgentReset()
{
	ResetData();
	StepCount = 0;
	OnEpisodeBegin();
}

void UAgent::SendInfo()
{
	if (bRequestDecision)
	{
		SendInfoToBrain();
		Reward = 0.0;
		GroupReward = 0.0;
		bRequestDecision = false;
	}
}

void UAgent::AgentIncrementStep()
{
	StepCount += 1;
}

void UAgent::AgentStep()
{
	if ((bRequestAction) && (Brain != nullptr))
	{
		bRequestAction = false;
		ActuatorManager->ExecuteActions();
	}
	if ((StepCount >= MaxStep) && (MaxStep > 0))
	{
		NotifyAgentDone(EDoneReason::MaxStepReached);
		AgentReset();
	}
}

void UAgent::DecideAction()
{
	if (ActuatorManager->GetStoredActions().ContinuousActions.Array == nullptr)
	{
		ResetData();
	}

	FActionBuffers Actions;
	if (Brain)
	{
		Actions = Brain->DecideAction();
	}
	else
	{
		Actions = FActionBuffers();
	}

	Info.CopyActions(Actions);
	ActuatorManager->UpdateActions(Actions);
}

int32 UAgent::GetDiscreteActions(const FActionBuffers& Actions, int32 Index)
{
	return Actions.DiscreteActions[Index];
}

template <typename T>
void UAgent::GetAllChildComponents(TArray<T*>& OutChildComponents)
{
	// Ensure the output array is empty
	OutChildComponents.Empty();

	// Get direct components of that type
	GetOwner()->GetComponents<T>(OutChildComponents);

	// Get all child actors of the parent actor
	TArray<AActor*> ChildActors;
	GetOwner()->GetAllChildActors(ChildActors, true); // 'true' to recursively get all descendants

	// Iterate through each child actor and get their components
	for (AActor* ChildActor : ChildActors)
	{
		if (ChildActor)
		{
			TArray<T*> ChildComponents;
			ChildActor->GetComponents<T>(ChildComponents);
			OutChildComponents.Append(ChildComponents);
		}
	}
}

void UAgent::Heuristic(FActionBuffers& ActionsOut) {}
void UAgent::CollectObservations_Implementation(UVectorSensor* Sensor) {}
void UAgent::Initialize_Implementation() {}
void UAgent::OnEpisodeBegin_Implementation() {}
void UAgent::OnActionReceived_Implementation(const FActionBuffers& Actions) {}
void UAgent::WriteDiscreteActionMask_Implementation(const TScriptInterface<IDiscreteActionMask>& ActionMask) {}
