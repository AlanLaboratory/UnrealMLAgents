#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BehaviorParameters.h"
#include "ISensor.h"
#include "AgentInfo.h"
#include "VectorSensor.h"
#include "VectorActuator.h"
#include "ActuatorManager.h"
#include "Agent.generated.h"

/**
 * @enum EDoneReason
 * @brief Enum describing the reasons why an episode ends for the agent.
 */
UENUM(BlueprintType)
enum class EDoneReason : uint8
{
	/** The episode was ended manually by calling EndEpisode. */
	DoneCalled UMETA(DisplayName = "Done Called"),

	/** The max steps for the Agent were reached. */
	MaxStepReached UMETA(DisplayName = "Max Step Reached"),

	/** The Agent was disabled. */
	Disabled UMETA(DisplayName = "Disabled")
};

/**
 * @class UAgentVectorActuator
 * @brief An implementation of VectorActuator specific to Agents.
 */
UCLASS()
class UNREALMLAGENTS_API UAgentVectorActuator : public UVectorActuator
{
	GENERATED_BODY()

public:
	/**
	 * @brief Specifies the built-in actuator type specific to agents in UnrealMLAgents.
	 * @return The type of built-in actuator.
	 */
	virtual EBuiltInActuatorType GetBuiltInActuatorType() const override;
};

/**
 * @class UAgent
 * @brief Represents an agent in the UnrealMLAgents environment that interacts with its surroundings by observing,
 * deciding on actions, and executing those actions.
 *
 * Agents operate in episodes and are governed by policies that decide their actions based on observations.
 * They can receive rewards, and the episode ends when the agent reaches a goal, fails, or reaches the maximum step
 * limit.
 */
UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALMLAGENTS_API UAgent : public UActorComponent, public IActionReceiver, public IHeuristicProvider
{
	GENERATED_BODY()

protected:
	/**
	 * @brief Called when the game starts.
	 * This method is used to initialize agent-related components when the simulation starts.
	 */
	virtual void BeginPlay() override;

public:
	/**
	 * @brief Called every frame to update the agent's logic and behavior.
	 * @param DeltaTime Time passed since the last frame.
	 * @param TickType Type of tick, such as a physics or regular tick.
	 * @param ThisTickFunction Information about this tick function.
	 */
	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**
	 * @brief Sets the agent's reward for the current step.
	 * @param NewReward The reward value to set.
	 */
	UFUNCTION(BlueprintCallable, Category = "Reward")
	void SetReward(float NewReward);

	/**
	 * @brief Adds to the agent's reward for the current step.
	 * @param NewReward The amount to add to the current reward.
	 */
	UFUNCTION(BlueprintCallable, Category = "Reward")
	void AddReward(float NewReward);

	/**
	 * @brief Ends the current episode for the agent.
	 */
	UFUNCTION(BlueprintCallable, Category = "Episode")
	void EndEpisode();

	/**
	 * @brief Signals that the episode was interrupted, typically when the max step is reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "Episode")
	void EpisodeInterrupted();

	/**
	 * @brief Requests a new decision from the agent's brain.
	 */
	UFUNCTION(BlueprintCallable, Category = "AgentAction")
	void RequestDecision();

	/**
	 * @brief Requests the agent to execute its last received action again.
	 */
	UFUNCTION(BlueprintCallable, Category = "AgentAction")
	void RequestAction();

	/**
	 * @brief Retrieves the action buffers that store the agent's most recent actions.
	 * @return The most recent action buffers.
	 */
	UFUNCTION(BlueprintCallable, Category = "AgentAction")
	FActionBuffers GetStoredActionBuffers();

	/**
	 * @brief Collects observations from the agent's sensors and stores them in the provided vector sensor.
	 * @param Sensor The vector sensor to which the observations will be added.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AgentObservation")
	void CollectObservations(UVectorSensor* Sensor);

	/**
	 * @brief Initializes the agent and prepares it for operation.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AgentInit")
	void Initialize();

	/**
	 * @brief Called when the agent receives an action from its brain.
	 * @param Actions The action buffers containing the agent's actions.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AgentAction")
	void OnActionReceived(const FActionBuffers& Actions) override;

	/**
	 * @brief Writes the action mask for discrete actions, preventing the agent from taking certain actions.
	 * @param ActionMask The mask that disables specific actions for this step.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AgentAction")
	void WriteDiscreteActionMask(const TScriptInterface<IDiscreteActionMask>& ActionMask) override;

	/**
	 * @brief Reads the discrete actions from the provided action buffer at a specified index.
	 * @param Actions The action buffer containing the agent's actions.
	 * @param Index The index from which to retrieve the discrete actions.
	 * @return The discrete action at the given index.
	 */
	UFUNCTION(BlueprintCallable, Category = "AgentObservation")
	int32 GetDiscreteActions(const FActionBuffers& Actions, int32 Index);

	/**
	 * @brief Called at the beginning of an episode to reset the agent's state.
	 */
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "AgentInit")
	void OnEpisodeBegin();

	/**
	 * @brief Implements heuristic decision-making logic for the agent.
	 * This function allows for manual or custom control of the agent's actions.
	 * @param ActionsOut The action buffers that will store the agent's actions.
	 */
	virtual void Heuristic(FActionBuffers& ActionsOut) override;

	/// The maximum number of steps the agent can take in a single episode before it is automatically terminated.
	UPROPERTY()
	int32 MaxStep;

	/// Whether the agent should stop updating observations.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AgentObservation")
	bool bStopUpdateObservation;

private:
	friend class UBehaviorParameters;

	/// Lazily initializes the agent, setting up necessary components and parameters.
	void LazyInitialize();

	/// Initializes the agent's actuators.
	void InitializeActuators();

	/// Initializes the agent's sensors.
	void InitializeSensors();

	/// Resets the agent's internal data, preparing it for a new episode.
	void ResetData();

	/// Sets a reward for the agent's group.
	void SetGroupReward(float NewReward);

	/// Adds to the group reward for the agent's group.
	void AddGroupReward(float Increment);

	/// Ends the episode and resets the agent, specifying the reason for completion.
	/// @param Reason The reason for ending the episode (e.g., DoneCalled, MaxStepReached).
	void EndEpisodeAndReset(EDoneReason Reason);

	/// Notifies the agent that it is done, either because the episode ended or the agent was disabled.
	/// @param DoneReason The reason the agent is marked as done.
	void NotifyAgentDone(EDoneReason DoneReason);

	/// Reloads the agent's policy, updating it with new parameters or models.
	void ReloadPolicy();

	/// Cleans up the agent's sensors, releasing any resources they may hold.
	void CleanupSensors();

	/// Updates the agent's sensors, ensuring they are collecting the correct data.
	void UpdateSensors();

	/// Resets the agent's sensors, clearing their state.
	void ResetSensors();

	/// Sends the agent's information to its brain, typically after a new decision is requested.
	void SendInfoToBrain();

	/**
	 * @brief Gets all child components of a specific type.
	 * @tparam T The type of components to retrieve.
	 * @param OutChildComponents The array to store the found child components.
	 */
	template <class T> void GetAllChildComponents(TArray<T*>& OutChildComponents);

	/**
	 * @brief Increments the agent's step count for the current episode.
	 */
	UFUNCTION()
	void AgentIncrementStep();

	/**
	 * @brief Sends the agent's decision to the brain for processing.
	 */
	UFUNCTION()
	void SendInfo();

	/**
	 * @brief Makes a decision for the agent based on the current observations and the agent's policy.
	 */
	UFUNCTION()
	void DecideAction();

	/**
	 * @brief Executes a step in the agent's lifecycle, updating its state and performing actions.
	 */
	UFUNCTION()
	void AgentStep();

	/**
	 * @brief Resets the agent, preparing it for a new episode.
	 */
	UFUNCTION()
	void AgentReset();

	UPROPERTY()
	UBehaviorParameters* PolicyFactory;

	UPROPERTY()
	UAgentVectorActuator* VectorActuator;

	UPROPERTY()
	UVectorSensor* CollectObservationsSensor;

	UPROPERTY()
	UActuatorManager* ActuatorManager;

	UPROPERTY()
	TArray<TScriptInterface<IISensor>> Sensors;

	UPROPERTY()
	FAgentInfo Info;

	UPROPERTY()
	TScriptInterface<IIPolicy> Brain;

	int32 GroupId;
	int32 StepCount;
	int32 CompletedEpisodes;
	int32 EpisodeId;

	float Reward;
	float GroupReward;
	float CumulativeReward;

	bool bInitialized;
	bool bRequestAction;
	bool bRequestDecision;
};
