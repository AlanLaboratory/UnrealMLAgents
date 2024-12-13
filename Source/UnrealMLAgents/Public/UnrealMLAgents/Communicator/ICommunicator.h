#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Sensors/ISensor.h"
#include "UnrealMLAgents/Actuators/ActionSpec.h"
#include "UnrealMLAgents/Grpc/CommunicatorObjects/AgentInfo.h"
#include "UObject/Interface.h"
#include "UObject/NoExportTypes.h"
#include "Delegates/DelegateCombinations.h"
#include "ICommunicator.generated.h"

// Structs

/**
 * @struct FCommunicatorInitParameters
 * @brief Holds the initialization parameters for the Unreal RL communicator.
 *
 * This struct contains information necessary to initialize the communication between the Unreal environment
 * and the external process, such as the port number, package version, and communication capabilities.
 */
USTRUCT(BlueprintType)
struct FCommunicatorInitParameters
{
	GENERATED_BODY()

	/** @brief The port number used for communication. */
	UPROPERTY(BlueprintReadWrite)
	int32 Port;

	/** @brief The name of the Unreal environment. */
	UPROPERTY(BlueprintReadWrite)
	FString Name;

	/** @brief The version of the Unreal package. */
	UPROPERTY(BlueprintReadWrite)
	FString UnrealPackageVersion;

	/** @brief The version of the Unreal communication protocol. */
	UPROPERTY(BlueprintReadWrite)
	FString UnrealCommunicationVersion;

	/** @brief Capabilities of the C# codebase used in the RL framework. */
	UPROPERTY(BlueprintReadWrite)
	FString CSharpCapabilities;
};

/**
 * @struct FUnrealRLInitParameters
 * @brief Contains initialization parameters sent from an external trainer to Unreal RL.
 *
 * This struct stores information such as the random seed, the number of areas in the environment, and the versions of
 * the Python libraries in use.
 */
USTRUCT(BlueprintType)
struct FUnrealRLInitParameters
{
	GENERATED_BODY()

	/** @brief The random number seed sent from the external trainer. */
	UPROPERTY(BlueprintReadWrite)
	int32 Seed;

	/** @brief The number of areas in the Unreal environment. */
	UPROPERTY(BlueprintReadWrite)
	int32 NumAreas;

	/** @brief The version of the Python library being used by the external trainer. */
	UPROPERTY(BlueprintReadWrite)
	FString PythonLibraryVersion;

	/** @brief The version of the communication protocol used by Python. */
	UPROPERTY(BlueprintReadWrite)
	FString PythonCommunicationVersion;

	/** @brief The capabilities of the trainer (external process). */
	UPROPERTY(BlueprintReadWrite)
	FString TrainerCapabilities;
};

/**
 * @struct FUnrealRLInputParameters
 * @brief Holds input parameters sent from the external trainer to Unreal RL.
 *
 * This struct contains input flags such as whether training is enabled or not.
 */
USTRUCT(BlueprintType)
struct FUnrealRLInputParameters
{
	GENERATED_BODY()

	/** @brief Boolean flag indicating if training is enabled. */
	UPROPERTY(BlueprintReadWrite)
	bool bIsTraining;
};

// Delegates

/** @brief Delegate for handling quit commands from the external trainer. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FQuitCommandHandler);

/** @brief Delegate for handling reset commands from the external trainer. */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FResetCommandHandler);

/**
 * @brief Delegate for handling input parameters received from the external trainer.
 *
 * @param InputParams Input parameters sent from the external trainer, including training flags.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRLInputReceivedHandler, const FUnrealRLInputParameters&, InputParams);

// Interface Definition

/**
 * @brief Unreal RL Communicator Interface for handling communication with external RL processes.
 *
 * This interface defines the communication between Unreal and an external process (e.g., a Python trainer).
 * It manages commands, input parameters, and the exchange of data like agent observations and actions.
 */
UINTERFACE(MinimalAPI)
class UCommunicatorInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class ICommunicatorInterface
 * @brief Interface for communicating between Unreal RL and an external training process.
 *
 * This interface provides methods to initialize communication, send agent observations, and receive agent actions.
 * It also defines events for handling quit and reset commands as well as receiving input parameters from the external
 * trainer.
 */
class UNREALMLAGENTS_API ICommunicatorInterface
{
	GENERATED_BODY()

public:
	/** @brief Event triggered when a quit command is received from the external trainer. */
	virtual FQuitCommandHandler& OnQuitCommandReceived() = 0;

	/** @brief Event triggered when a reset command is received from the external trainer. */
	virtual FResetCommandHandler& OnResetCommandReceived() = 0;

	/** @brief Event triggered when input parameters are received from the external trainer. */
	virtual FRLInputReceivedHandler& OnRLInputReceived() = 0;

	// Methods

	/**
	 * @brief Initializes communication between Unreal and the external trainer.
	 *
	 * This method sets up the communication link between Unreal and the external process by exchanging initialization
	 * parameters.
	 *
	 * @param InitParameters The initialization parameters sent from Unreal.
	 * @param InitParametersOut The initialization parameters received from the external trainer.
	 * @return True if initialization was successful, false otherwise.
	 */
	virtual bool Initialize(
		const FCommunicatorInitParameters& InitParameters, FUnrealRLInitParameters& InitParametersOut) = 0;

	/**
	 * @brief Registers a new brain (agent) with the communicator.
	 *
	 * This method registers an agent's brain with the communicator, allowing the brain to exchange actions and
	 * observations.
	 *
	 * @param Name A unique identifier for the brain.
	 * @param ActionSpec The specification of the actions the brain can take.
	 */
	virtual void SubscribeBrain(const FString& Name, FActionSpec ActionSpec) = 0;

	/**
	 * @brief Sends observations from an agent to the external trainer.
	 *
	 * This method is used to send agent observations to the external trainer, allowing it to process these observations
	 * and return actions.
	 *
	 * @param BrainKey The key identifying the brain to which the agent belongs.
	 * @param Info The agent's current state and observations.
	 * @param Sensors A list of the sensors attached to the agent.
	 */
	virtual void PutObservations(
		const FString& BrainKey, const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) = 0;

	/**
	 * @brief Requests a decision from the external trainer for all agents.
	 *
	 * This method is called to signal that all agents are ready to receive actions and that the external trainer should
	 * process a batch of observations.
	 */
	virtual void DecideBatch() = 0;

	/**
	 * @brief Retrieves the actions for a specific agent from the external trainer.
	 *
	 * This method fetches the actions that the external trainer has determined for a specific agent based on the
	 * observations sent.
	 *
	 * @param Key The key identifying the brain (agent) whose actions are requested.
	 * @param AgentId The ID of the agent within that brain whose actions are requested.
	 * @return The action buffers containing the actions for the agent.
	 */
	virtual const FActionBuffers GetActions(const FString& Key, int32 AgentId) = 0;
};
