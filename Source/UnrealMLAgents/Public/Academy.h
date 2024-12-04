#pragma once

#include "CoreMinimal.h"
#include "Delegates/DelegateCombinations.h"
#include "UObject/NoExportTypes.h"
#include "RpcCommunicator.h"
#include "RecursionChecker.h"
#include "RemotePolicy.h"
#include "Tickable.h"
#include "Academy.generated.h"

// Define the delegate types
/**
 * @brief Delegate triggered when the action decision-making process is initiated.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDecideActionDelegate);

/**
 * @brief Delegate triggered when the Academy is destroyed.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDestroyActionDelegate);

/**
 * @brief Delegate triggered after an agent increments its step count.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAgentIncrementStepDelegate);

/**
 * @brief Delegate triggered before an agent steps, passing the current step count.
 * @param StepCount The current step count of the agent.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAgentPreStepDelegate, int32, StepCount);

/**
 * @brief Delegate triggered when the agent sends its state.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAgentSendStateDelegate);

/**
 * @brief Delegate triggered when the agent performs an action.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAgentActDelegate);

/**
 * @brief Delegate triggered when a force reset is requested for the agent.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAgentForceResetDelegate);

/**
 * @brief Delegate triggered when the environment is reset.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEnvironmentReset);

/**
 * @class UAcademy
 * @brief The core class managing the simulation environment in the UnrealMLAgents system.
 *
 * UAcademy is responsible for managing the environment, handling agent interactions, stepping through
 * the environment's simulation, and coordinating the communication between agents and an external training system.
 *
 * The Academy controls the entire simulation lifecycle, including resetting the environment and tracking
 * episode progress. It also manages the communication pipeline with remote agents or policies.
 *
 * This class is designed as a singleton, ensuring that only one instance of the Academy is active at any time.
 */
UCLASS()
class UNREALMLAGENTS_API UAcademy : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Updates the Academy at each tick, stepping through the environment's simulation.
	 *
	 * This method is called every frame (or every tick) and updates the simulation by stepping through
	 * the environment. It also processes agent actions and observations as needed.
	 *
	 * @param DeltaTime The time passed since the last frame, used to control the tick rate of the simulation.
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Checks if the Academy is currently tickable.
	 *
	 * Determines whether the Academy should be ticked in the current frame. This is used to control when
	 * the Academy should update its internal state.
	 *
	 * @return True if the Academy should be updated every tick, false otherwise.
	 */
	virtual bool IsTickable() const override;

	/**
	 * @brief Retrieves the statistical ID used for performance monitoring.
	 *
	 * This method is used for tracking performance metrics within the simulation, allowing the Academy
	 * to report its usage to Unreal Engine’s stat system.
	 *
	 * @return The stat ID used for performance tracking.
	 */
	virtual TStatId GetStatId() const override;

	/// Total number of steps taken in the simulation since the Academy started.
	int32 TotalStepCount;

	/// Current episode count within the UnrealMLAgents simulation.
	int32 EpisodeCount;

	/// Step count within the current episode.
	int32 StepCount;

	/// Number of areas or regions within the simulation environment.
	int32 NumAreas;

	/// Random seed used for inference in the environment.
	int32 InferenceSeed;

	/**
	 * @brief Retrieves the singleton instance of the Academy.
	 *
	 * This method returns the single instance of the UAcademy class. It ensures that only one Academy
	 * exists at a time, which manages the entire simulation.
	 *
	 * @return The singleton instance of the Academy.
	 */
	static UAcademy* GetInstance();

	/**
	 * @brief Shuts down the Academy and releases its resources.
	 *
	 * This method is responsible for cleaning up and shutting down the Academy when the simulation ends
	 * or the Academy is no longer needed. It ensures that any allocated resources are properly released.
	 *
	 * @param bIsSimulating Whether the environment is in simulation mode.
	 */
	void Dispose(bool bIsSimulating);

	/**
	 * @brief Shuts down the Academy, releasing its resources.
	 *
	 * This overload is used when the simulation mode is not important, and all resources allocated by
	 * the Academy need to be released.
	 */
	void Dispose();

	/**
	 * @brief Steps through the environment, advancing the simulation.
	 *
	 * This method processes a single simulation step, updating the environment and triggering agent actions.
	 */
	void EnvironmentStep();

	/**
	 * @brief Whether the Academy has been initialized
	 *
	 * This method return True if the Academy has been well initialized.
	 */
	static bool IsInitialized() { return Instance != nullptr; }

	/**
	 * @brief Checks if the communicator is currently active.
	 *
	 * This method determines whether the communicator responsible for connecting agents with external
	 * training systems is active. The communicator must be active for agents to send and receive data
	 * during training.
	 *
	 * @return True if the communicator is active, false otherwise.
	 */
	bool IsCommunicatorOn();

	// Declare events related to agent and environment lifecycle.

	/**
	 * @brief Triggered when the Academy starts the action decision-making process.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FDecideActionDelegate OnDecideAction;

	/**
	 * @brief Triggered when the Academy is destroyed.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FDestroyActionDelegate OnDestroyAction;

	/**
	 * @brief Triggered after an agent increments its step count.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FAgentIncrementStepDelegate OnAgentIncrementStep;

	/**
	 * @brief Triggered before an agent steps, passing the current step count.
	 * @param StepCount The current step count of the agent.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FAgentPreStepDelegate OnAgentPreStep;

	/**
	 * @brief Triggered when the agent sends its state.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FAgentSendStateDelegate OnAgentSendState;

	/**
	 * @brief Triggered when the agent performs an action.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FAgentActDelegate OnAgentAct;

	/**
	 * @brief Triggered when a force reset is requested for the agent.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FAgentForceResetDelegate OnAgentForceReset;

	/**
	 * @brief Triggered when the environment is reset.
	 */
	UPROPERTY(BlueprintAssignable, Category = "Academy Events")
	FOnEnvironmentReset OnEnvironmentReset;

private:
	/**
	 * @brief Private constructor to enforce the singleton pattern.
	 */
	UAcademy();

	/// API version of the Academy.
	const FString ApiVersion = "0.1.0";

	/// Package version of the Academy.
	const FString PackageVersion = "1.0.0.dev0";

	/// The command line port for communicating with external systems.
	int32 Port = 5004;

	/// Command line flag for specifying the port used for communication.
	FString PortCommandLineFlag = "mlAgentPort=";

	/// The singleton instance of the Academy.
	static UAcademy* Instance;

	/// Used to detect recursion in the Academy’s stepping process.
	URecursionChecker* StepRecursionChecker = NewObject<URecursionChecker>();

	/// Whether the Academy has been fully initialized.
	bool bInitialized;

	/// Whether stepping through the environment is enabled.
	bool bEnableStepping;

	/// Whether the first reset has occurred.
	bool bHadFirstReset;

	/// Communicator used for interacting with remote agents or policies.
	UPROPERTY()
	URpcCommunicator* RpcCommunicator;

	/**
	 * @brief Lazily initializes the Academy.
	 *
	 * This method is used to set up the Academy's internal components and prepare the environment for stepping.
	 * It is called when the Academy needs to be initialized but allows the initialization to be delayed
	 * until the first time it is required.
	 */
	void LazyInitialize();

	/**
	 * @brief Initializes the environment and prepares it for stepping.
	 */
	void InitializeEnvironment();

	/**
	 * @brief Parses command line arguments to configure the Academy.
	 */
	void ParseCommandLineArgs();

	/**
	 * @brief Forces a full reset of the environment and agents.
	 */
	void ForcedFullReset();

	/**
	 * @brief Resets the environment without clearing global state.
	 */
	void EnvironmentReset();

	/**
	 * @brief Resets all actions for the environment.
	 */
	void ResetActions();

	/**
	 * @brief Handles reset commands received from the communicator.
	 */
	UFUNCTION()
	void OnResetCommand();

	/**
	 * @brief Handles quit commands received from the communicator.
	 */
	UFUNCTION()
	void OnQuitCommandReceived();

	friend class URemotePolicy;
};
