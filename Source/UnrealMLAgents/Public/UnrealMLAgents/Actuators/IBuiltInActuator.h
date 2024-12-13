#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBuiltInActuator.generated.h"

/**
 * @enum EBuiltInActuatorType
 * @brief Identifiers for built-in actuator types.
 *
 * This enumeration provides identifiers for the built-in actuator types used in the system.
 * These identifiers are primarily for analytics purposes and are not intended to be used
 * for runtime decisions.
 */
UENUM(BlueprintType)
enum class EBuiltInActuatorType : uint8
{
	/**
	 * @brief Default type if the actuator type cannot be determined.
	 */
	Unknown UMETA(DisplayName = "Unknown"),

	/**
	 * @brief The actuator type used by the agent for vector-based actions.
	 *
	 * This corresponds to the `AgentVectorActuator`, which is commonly used by agents
	 * to perform actions represented as vectors.
	 */
	AgentVectorActuator UMETA(DisplayName = "Agent Vector Actuator"),

	/**
	 * @brief A general-purpose vector actuator type.
	 *
	 * This type corresponds to actuators that process vector-based actions,
	 * similar to the `VectorActuator`.
	 */
	VectorActuator UMETA(DisplayName = "Vector Actuator"),
};

/**
 * @interface IBuiltInActuator
 * @brief Interface for built-in actuators.
 *
 * The IBuiltInActuator interface is implemented by built-in actuators that are part of the UnrealMLAgents system.
 * User-implemented actuators do not need to implement this interface. It provides a method for retrieving
 * the type of the built-in actuator, which is used primarily for analytics purposes.
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UBuiltInActuator : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IBuiltInActuator
 * @brief Interface for retrieving the type of a built-in actuator.
 *
 * This interface defines a method for obtaining the type of built-in actuators (such as `AgentVectorActuator`
 * or `VectorActuator`). The types are used for identification and analytics purposes.
 */
class UNREALMLAGENTS_API IBuiltInActuator
{
	GENERATED_BODY()

public:
	/**
	 * @brief Retrieves the type of the built-in actuator.
	 *
	 * This method returns the type of the built-in actuator, represented as an `EBuiltInActuatorType`.
	 * The type is used for identifying the actuator and for analytics tracking.
	 *
	 * @return The type of the built-in actuator.
	 */
	virtual EBuiltInActuatorType GetBuiltInActuatorType() const = 0;
};
