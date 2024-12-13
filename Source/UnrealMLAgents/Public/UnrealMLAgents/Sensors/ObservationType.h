#pragma once

#include "CoreMinimal.h"
#include "ObservationType.generated.h"

/**
 * @enum EObservationType
 * @brief Enum representing the type of observation collected by a sensor.
 *
 * The `EObservationType` enum defines different types of observations that a sensor can collect
 * in a reinforcement learning environment. This classification helps distinguish between generic observations
 * and specific goal-related signals.
 */
UENUM(BlueprintType)
enum class EObservationType : uint8
{
	/**
	 * @brief The sensor collects generic observations.
	 *
	 * This type is used when the sensor collects general information about the environment or the agent's state.
	 */
	Default = 0 UMETA(DisplayName = "Default"),

	/**
	 * @brief The sensor collects goal-related information.
	 *
	 * This type is used when the sensor collects information that directly relates to the agent's goals or objectives
	 * in the environment, such as the location of a target or goal signal.
	 */
	GoalSignal = 1 UMETA(DisplayName = "Goal Signal")
};
