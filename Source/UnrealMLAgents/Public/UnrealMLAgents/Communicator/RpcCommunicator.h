#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Actuators/ActionSpec.h"
#include "UnrealMLAgents/Grpc/CommunicatorObjects/AgentInfo.h"
#include "grpc++/grpc++.h"
#include "UnrealMLAgents/Communicator/ICommunicator.h"
#include "UnrealMLAgents/Sensors/ObservationWriter.h"
#include "google/protobuf/repeated_field.h"
#include "ueagents_envs/communicator_objects/unreal_to_external.grpc.pb.h"
#include "ueagents_envs/communicator_objects/unreal_rl_output.pb.h"
#include "ueagents_envs/communicator_objects/unreal_message.pb.h"
#include "ueagents_envs/communicator_objects/unreal_rl_input.pb.h"

// This should fix error C2039: 'GetObjectW': is not a member of 'TScriptInterface<IBlendableInterface>'
// Issues seems to be related to an issue in the generated files.
#ifdef GetObject
	#undef GetObject
#endif

#include "RpcCommunicator.generated.h"

/**
 * @class URpcCommunicator
 * @brief A communicator class that manages gRPC-based communication between Unreal Engine and external systems.
 *
 * This class implements the communication pipeline using gRPC for reinforcement learning between Unreal Engine
 * and an external system, typically a Python-based training server. It handles the transfer of agent observations,
 * actions, and other commands.
 */
UCLASS()
class UNREALMLAGENTS_API URpcCommunicator : public UObject, public ICommunicatorInterface
{
	GENERATED_BODY()

public:
	/**
	 * @brief Event handler for receiving quit commands from the external system.
	 *
	 * @return A reference to the QuitCommandHandler.
	 */
	virtual FQuitCommandHandler& OnQuitCommandReceived() override;

	/**
	 * @brief Event handler for receiving reset commands from the external system.
	 *
	 * @return A reference to the ResetCommandHandler.
	 */
	virtual FResetCommandHandler& OnResetCommandReceived() override;

	/**
	 * @brief Event handler for receiving input parameters from the external system.
	 *
	 * @return A reference to the RLInputReceivedHandler.
	 */
	virtual FRLInputReceivedHandler& OnRLInputReceived() override;

	/**
	 * @brief Initializes the communicator with input parameters and sets up the gRPC channel.
	 *
	 * @param InitParameters Input parameters for initializing communication.
	 * @param InitParametersOut Output parameters received from the external system.
	 * @return True if initialization was successful, false otherwise.
	 */
	virtual bool Initialize(
		const FCommunicatorInitParameters& InitParameters, FUnrealRLInitParameters& InitParametersOut) override;

	/**
	 * @brief Subscribes a brain to the communicator by registering the brain's name and action specification.
	 *
	 * @param Name The name of the brain (behavior).
	 * @param ActionSpec The specification of the brain's action space.
	 */
	virtual void SubscribeBrain(const FString& Name, FActionSpec ActionSpec) override;

	/**
	 * @brief Sends agent observations to the external system for decision-making.
	 *
	 * @param BrainKey The key of the brain to which the observations belong.
	 * @param Info Information about the agent's current state.
	 * @param Sensors A list of sensors that generate the observations.
	 */
	virtual void PutObservations(
		const FString& BrainKey, const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) override;

	/**
	 * @brief Requests the external system to decide actions for the current batch of agents.
	 */
	virtual void DecideBatch() override;

	/**
	 * @brief Retrieves the actions decided by the external system for a specific agent.
	 *
	 * @param Key The key of the brain for which actions are requested.
	 * @param AgentId The ID of the agent for which actions are requested.
	 * @return A constant reference to the action buffers containing the agent's actions.
	 */
	virtual const FActionBuffers GetActions(const FString& Key, int32 AgentId) override;

	/**
	 * @brief Initializes properties after the object is constructed.
	 */
	virtual void PostInitProperties() override;

	/**
	 * @brief Closes the communication channel gracefully.
	 */
	void Dispose();

private:
	/** Indicates whether the communication channel is open. */
	bool bIsOpen;

	/** The gRPC client stub used for communicating with the external system. */
	std::unique_ptr<communicator_objects::UnrealToExternalProto::Stub> Stub;

	/** The gRPC communication channel used for client-server communication. */
	std::shared_ptr<grpc::Channel> Channel;

	/**
	 * @brief Notifies the system to quit and shuts down the gRPC communication channel.
	 */
	UFUNCTION()
	void NotifyQuitAndShutDownChannel();

	/**
	 * @brief Initializes the communication with the external system, including port setup and message exchange.
	 *
	 * @param Port The port number used for gRPC communication.
	 * @param UnrealOutput The output data from Unreal Engine.
	 * @param UnrealInput The input data from the external system.
	 * @return The UnrealInputProto structure containing initialization data.
	 */
	communicator_objects::UnrealInputProto Initialize(int32 Port,
		const communicator_objects::UnrealOutputProto&		UnrealOutput,
		communicator_objects::UnrealInputProto&				UnrealInput);

	/**
	 * @brief Wraps a message in a gRPC-compatible format for communication.
	 *
	 * @param Content The content of the message to be sent.
	 * @param Status The status code of the message.
	 * @return A properly formatted UnrealMessageProto message.
	 */
	static communicator_objects::UnrealMessageProto WrapMessage(
		const communicator_objects::UnrealOutputProto* Content, int32 Status);

	/**
	 * @brief Verifies that the communication versions of Unreal and Python are compatible.
	 *
	 * @param unityCommunicationVersion The communication version of Unreal Engine.
	 * @param pythonApiVersion The communication version of the Python server.
	 * @return True if the versions are compatible, false otherwise.
	 */
	static bool CheckCommunicationVersionAreCompatible(
		const FString& unityCommunicationVersion, const FString& pythonApiVersion);

	/**
	 * @brief Establishes the communication channel with the external system using the specified port.
	 *
	 * @param Port The port number to use for communication.
	 * @return True if the connection was established successfully, false otherwise.
	 */
	bool EstablishConnection(int32 Port);

	/**
	 * @brief Sends and receives a message to/from the external system over gRPC.
	 *
	 * @param Request The message to send to the external system.
	 * @param Response The response received from the external system.
	 * @return True if the message exchange was successful, false otherwise.
	 */
	bool SendAndReceiveMessage(
		const communicator_objects::UnrealMessageProto& Request, communicator_objects::UnrealMessageProto& Response);

	/**
	 * @brief Caches the action specification for a specific brain.
	 *
	 * @param Name The name of the brain.
	 * @param ActionSpec The action specification to be cached.
	 */
	void CacheActionSpec(const FString& Name, FActionSpec ActionSpec);

	/**
	 * @brief Sends a batched message containing agent observations and receives a response from the external system.
	 */
	void SendBatchedMessageHelper();

	/**
	 * @brief Exchanges data between Unreal Engine and the external system during communication.
	 *
	 * @param UnrealOutput The output data from Unreal Engine.
	 * @return The input data received from the external system.
	 */
	communicator_objects::UnrealInputProto Exchange(const communicator_objects::UnrealOutputProto* UnrealOutput);

	/**
	 * @brief Retrieves temporary initialization output data for Unreal's RL environment.
	 *
	 * @return A shared pointer to the UnrealRLInitializationOutputProto structure.
	 */
	TSharedPtr<communicator_objects::UnrealRLInitializationOutputProto> GetTempUnrealRlInitializationOutput();

	/**
	 * @brief Updates the sent action specification after initialization.
	 *
	 * @param Output The initialization output data from the external system.
	 */
	void UpdateSentActionSpec(const communicator_objects::UnrealRLInitializationOutputProto* Output);

	/**
	 * @brief Sends a command event to the external system, such as quitting or resetting the environment.
	 *
	 * @param Command The command to send.
	 */
	void SendCommandEvent(communicator_objects::CommandProto Command);

	// Extension Functions
	/**
	 * @brief Converts an Unreal Engine sensor's observation into a gRPC ObservationProto message.
	 *
	 * @param Sensor The Unreal Engine sensor interface that gathers observations.
	 * @param ObsWriter The writer used to record the sensor's observations into the ObservationProto.
	 * @return The generated gRPC `ObservationProto` message for communication with external systems.
	 */
	communicator_objects::ObservationProto GetObservationProto(
		TScriptInterface<IISensor> Sensor, ObservationWriter& ObsWriter);

	/**
	 * @brief Converts gRPC `AgentActionProto` messages into Unreal Engine's action buffers.
	 *
	 * This method is responsible for translating the actions provided by the external system
	 * into Unreal Engine's `FActionBuffers` format for use by agents.
	 *
	 * @param Proto The gRPC `AgentActionProto` received from the external system.
	 * @return Unreal Engine `FActionBuffers` containing the actions to be performed by the agent.
	 */
	FActionBuffers ToActionBuffers(const communicator_objects::AgentActionProto& Proto);

	/**
	 * @brief Converts Unreal Engine's action specification into a gRPC `ActionSpecProto`.
	 *
	 * This method takes Unreal Engine's action specification and transforms it into the
	 * protobuf format `ActionSpecProto` used by external training systems (such as Python).
	 *
	 * @param ActionSpec The Unreal Engine action specification describing the action space.
	 * @return A `ActionSpecProto` message that can be communicated externally.
	 */
	communicator_objects::ActionSpecProto ToActionSpecProto(const FActionSpec& ActionSpec);

	/**
	 * @brief Converts a list of gRPC agent actions to Unreal Engine action buffers.
	 *
	 * This method processes a list of gRPC agent actions and converts them into a format that can be
	 * interpreted by Unreal Engine agents.
	 *
	 * @param Proto The list of `UnrealRLInputProto_ListAgentActionProto` actions from the external system.
	 * @return A list of Unreal Engine `FActionBuffers` corresponding to the actions.
	 */
	TArray<FActionBuffers> ToAgentActionList(const communicator_objects::UnrealRLInputProto_ListAgentActionProto Proto);

	/**
	 * @brief Converts Unreal Engine's `FActionSpec` and training status into a gRPC `BrainParametersProto`.
	 *
	 * This method creates a `BrainParametersProto` message from Unreal Engine's action specification and
	 * agent status (such as whether it is training), which is then sent to the external system.
	 *
	 * @param ActionSpec The action specification for the agent.
	 * @param Name The name of the agent's brain.
	 * @param bIsTraining Whether the agent is currently in training mode.
	 * @return The gRPC `BrainParametersProto` message to be sent to external systems.
	 */
	communicator_objects::BrainParametersProto ToBrainParametersProto(
		const FActionSpec& ActionSpec, FString Name, bool bIsTraining);

	/**
	 * @brief Converts Unreal Engine's `FAgentInfo` into a gRPC `AgentInfoProto` message.
	 *
	 * This method translates the information about an agent's state into a format (`AgentInfoProto`)
	 * that can be understood by external systems.
	 *
	 * @param Info The Unreal Engine `FAgentInfo` struct containing the agent's state and details.
	 * @return A `AgentInfoProto` message for communication with external systems.
	 */
	communicator_objects::AgentInfoProto ToAgentInfoProto(const FAgentInfo& Info);

	/** Event handler for quit commands. */
	FQuitCommandHandler QuitCommandReceived;

	/** Event handler for reset commands. */
	FResetCommandHandler ResetCommandReceived;

	/** Event handler for RL input commands. */
	FRLInputReceivedHandler RLInputReceived;

	/** Indicates whether communication is needed in the current step. */
	bool bNeedCommunicateThisStep;

	/** Writer for capturing agent observations. */
	ObservationWriter ObsWriter;

	/** A map storing agent decision requests for each brain. */
	TMap<FString, TArray<int32>> OrderedAgentsRequestingDecisions;

	/** A pointer to the current UnrealRLOutput being sent to the external system. */
	TUniquePtr<communicator_objects::UnrealRLOutputProto> CurrentUnrealRlOutput;

	/** A map storing the last actions received for each brain and agent. */
	TMap<FString, TMap<int32, FActionBuffers>> LastActionsReceived;

	/** A set of brain keys that have been sent to the external system. */
	TSet<FString> SentBrainKeys;

	/** A map of unsent brain keys and their corresponding action specifications. */
	TMap<FString, FActionSpec> UnsentBrainKeys;

	/** A list of behavior names corresponding to the agent brains. */
	TArray<FString> BehaviorNames;
};
