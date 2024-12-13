#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "UnrealMLAgents/Actuators/ActionSpec.h"
#include "UnrealMLAgents/Actuators/IDiscreteActionMask.h"
#include "UnrealMLAgents/Actuators/IActionReceiver.h"
#include "IActuator.generated.h"

/**
 * @class IActuator
 * @brief An abstraction that facilitates the execution of actions in a reinforcement learning environment.
 *
 * The IActuator interface defines the core methods for executing actions, retrieving action specifications,
 * and resetting internal state. It is designed to interact with the RL system by providing the necessary
 * infrastructure for agents to act based on their observations and policies.
 */
UINTERFACE(MinimalAPI)
class UActuator : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IActuator
 * @brief Interface for classes that facilitate the execution of actions in reinforcement learning.
 *
 * The IActuator interface works in tandem with `IActionReceiver` to process and execute actions
 * based on the action buffers provided by a reinforcement learning model or heuristic policy.
 */
class IActuator
{
	GENERATED_BODY()

public:
	/**
	 * @brief Retrieves the action specification for this actuator.
	 *
	 * The action specification defines the structure of the action space, including the number of
	 * continuous and discrete actions available to the actuator.
	 *
	 * @return A constant reference to the action specification.
	 */
	virtual const FActionSpec GetActionSpec() const = 0;

	/**
	 * @brief Gets the name of this actuator.
	 *
	 * This name is used to identify and sort actuators, especially in multi-agent or multi-actuator scenarios.
	 *
	 * @return The name of the actuator.
	 */
	virtual const FString GetName() const = 0;

	/**
	 * @brief Resets the internal state of the actuator.
	 *
	 * This method is called at the end of an agent's episode. Implementations may leave this empty if no
	 * reset behavior is needed.
	 */
	virtual void ResetData() = 0;

	/**
	 * @brief Provides heuristic-based decisions for the actuator.
	 *
	 * This method allows the actuator to make heuristic decisions, typically used when the agent's behavior
	 * is not controlled by a machine learning model but by predefined rules or user input.
	 *
	 * @param ActionBuffersOut The action buffers to be filled with heuristic-based actions.
	 */
	virtual void Heuristic(FActionBuffers& ActionBuffersOut) = 0;

	/**
	 * @brief Executes actions based on the contents of the action buffers.
	 *
	 * This method is called to process and apply the actions specified in the action buffers. The actions are
	 * executed according to the agent's current policy and the structure defined by the action specification.
	 *
	 * @param ActionBuffers The buffers containing the continuous and discrete actions to be executed.
	 */
	virtual void OnActionReceived(const FActionBuffers& ActionBuffers) = 0;

	/**
	 * @brief Modifies the masks for discrete actions.
	 *
	 * This method modifies the action masks for discrete actions, allowing the actuator to selectively enable
	 * or disable certain actions based on the current state of the environment or agent.
	 *
	 * @param ActionMask The discrete action mask to be applied.
	 */
	virtual void WriteDiscreteActionMask(const TScriptInterface<IDiscreteActionMask>& ActionMask) = 0;
};

/**
 * @class IActuatorExtensions
 * @brief Helper methods shared by all classes that implement IActuator.
 *
 * This class provides utility functions for actuators, allowing easy access to information such as the
 * total number of actions (both continuous and discrete) available to an actuator.
 */
class IActuatorExtensions
{
public:
	/**
	 * @brief Returns the total number of actions for the actuator.
	 *
	 * This method sums the number of continuous and discrete actions defined in the action specification,
	 * providing a total count of available actions.
	 *
	 * @param Actuator The actuator for which to calculate the total number of actions.
	 * @return The total number of continuous and discrete actions.
	 */
	static int32 TotalNumberOfActions(const IActuator& Actuator)
	{
		return Actuator.GetActionSpec().NumContinuousActions + Actuator.GetActionSpec().GetNumDiscreteActions();
	}
};
