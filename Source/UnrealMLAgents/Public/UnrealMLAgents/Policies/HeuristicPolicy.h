#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Policies/IPolicy.h"
#include "UnrealMLAgents/Grpc/CommunicatorObjects/AgentInfo.h"
#include "UnrealMLAgents/Sensors/ISensor.h"
#include "UnrealMLAgents/Actuators/ActuatorManager.h"
#include "UnrealMLAgents/Sensors/ObservationWriter.h"
#include "HeuristicPolicy.generated.h"

/**
 * @class UHeuristicPolicy
 * @brief A policy class that uses a hand-coded heuristic method to determine agent actions.
 *
 * The UHeuristicPolicy class is responsible for determining the actions that an agent should take
 * based on a predefined heuristic logic. This class works closely with the actuator system to apply
 * heuristic actions at each decision request. It is particularly useful when no machine learning model
 * is used, and manual decision logic is provided.
 */
UCLASS()
class UNREALMLAGENTS_API UHeuristicPolicy : public UObject, public IIPolicy
{
	GENERATED_BODY()

private:
	/** @brief A reference to the actuator manager controlling the agent's actions. */
	UPROPERTY()
	UActuatorManager* ActuatorManager;

	/** @brief The buffers storing the actions determined by the heuristic policy. */
	UPROPERTY()
	FActionBuffers ActionBuffers;

	/** @brief A list of null entries for discarded observations during the heuristic process. */
	UPROPERTY()
	TArray<FString> NullList;

	/** @brief Writer for handling the agent's observations during decision-making. */
	ObservationWriter ObservationWriter;

	/** @brief A flag indicating whether the agent's episode has completed. */
	bool bDone;

	/** @brief A flag indicating whether a decision has been requested for the agent. */
	bool bDecisionRequested;

public:
	/**
	 * @brief Initializes the heuristic policy with an actuator manager and action specification.
	 *
	 * This function sets up the heuristic policy by associating it with an actuator manager and the
	 * action specification (defining the action space for the agent).
	 *
	 * @param InActuatorManager The actuator manager that controls the agent's actions.
	 * @param ActionSpec The action specification defining the structure of the agent's action space.
	 */
	void Initialize(UActuatorManager* InActuatorManager, const FActionSpec& ActionSpec);

	/**
	 * @brief Requests a decision based on the agent's current state and observations.
	 *
	 * This function triggers a heuristic decision request, during which the agent's current state and
	 * sensor data are evaluated. The decision process can be asynchronous and involves collecting observations.
	 *
	 * @param Info The current state and information of the agent.
	 * @param Sensors A list of sensors attached to the agent that provide observation data.
	 */
	virtual void RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) override;

	/**
	 * @brief Determines the agent's next action based on the heuristic policy.
	 *
	 * This function applies the heuristic logic to the agent's current state and returns the action buffers
	 * containing the actions that the agent should take. It only executes if a decision has been requested.
	 *
	 * @return A constant reference to the action buffers containing the actions decided by the heuristic policy.
	 */
	virtual const FActionBuffers& DecideAction() override;
};
