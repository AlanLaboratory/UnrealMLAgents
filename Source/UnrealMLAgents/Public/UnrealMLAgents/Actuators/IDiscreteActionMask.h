#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IDiscreteActionMask.generated.h"

/**
 * @interface IDiscreteActionMask
 * @brief Interface for writing a mask to disable specific discrete actions for agents.
 *
 * The IDiscreteActionMask interface allows for controlling which discrete actions an agent can take
 * in the next decision-making step. By masking certain actions, the agent is prevented from performing
 * those actions at the next decision.
 */
UINTERFACE(MinimalAPI)
class UDiscreteActionMask : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IDiscreteActionMask
 * @brief Interface for setting action masks in discrete action spaces.
 *
 * This interface defines a method for enabling or disabling specific actions within a discrete action space.
 * It is primarily used to restrict the available actions that an agent can take based on the environment state.
 */
class IDiscreteActionMask
{
	GENERATED_BODY()

public:
	/**
	 * @brief Enables or disables a specific action for the next decision.
	 *
	 * This method controls whether a specific action in a given branch is enabled or disabled. By default,
	 * all actions are enabled, but this method can be used to mask out certain actions that the agent
	 * should not be able to perform at the next decision step.
	 *
	 * @param Branch The branch of the action space for which the action will be masked.
	 * @param ActionIndex The index of the specific action to enable or disable.
	 * @param bIsEnabled Whether the action should be enabled (true) or disabled (false).
	 */
	virtual void SetActionEnabled(int32 Branch, int32 ActionIndex, bool bIsEnabled) = 0;
};
