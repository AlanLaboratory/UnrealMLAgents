#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UnrealMLAgents/Grpc/CommunicatorObjects/AgentInfo.h"
#include "UnrealMLAgents/Sensors/ISensor.h"
#include "IPolicy.generated.h"

/**
 * @interface IIPolicy
 * @brief Interface for managing decision requests and actions for agents in a reinforcement learning environment.
 *
 * The `IIPolicy` interface defines methods for requesting decisions and retrieving actions for agents.
 * The decision-making process can be deferred to allow batching of requests before actions are finally determined.
 * It works closely with the agent's brain, ensuring actions are updated based on the latest decisions.
 */
UINTERFACE(MinimalAPI)
class UIPolicy : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IIPolicy
 * @brief Interface that handles decision requests and action determination for agents.
 *
 * The `IIPolicy` interface defines the communication between an agent and its policy (brain). Agents
 * use this interface to request decisions and to retrieve the actions that the policy has determined.
 * It is designed to support deferred decision-making, allowing the policy to make decisions at a later
 * time, potentially batching multiple decision requests.
 */
class UNREALMLAGENTS_API IIPolicy
{
	GENERATED_BODY()

public:
	/**
	 * @brief Requests a decision for the agent.
	 *
	 * This method signals to the policy that the agent requires a decision based on its current state and
	 * observations. The decision is not taken immediately, allowing for the possibility of batching multiple
	 * decision requests.
	 *
	 * @param Info The current state and information of the agent.
	 * @param Sensors A list of sensors attached to the agent that provide observation data.
	 */
	virtual void RequestDecision(const FAgentInfo& Info, TArray<TScriptInterface<IISensor>>& Sensors) = 0;

	/**
	 * @brief Forces the policy to decide the agent's next action.
	 *
	 * If a decision has not yet been made, this method forces the policy to take action immediately.
	 * This ensures that the agent's actions are updated based on the latest available decision.
	 *
	 * @return A constant reference to the `FActionBuffers` containing the actions determined by the policy.
	 */
	virtual const FActionBuffers& DecideAction() = 0;
};
