#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IHeuristicProvider.generated.h"

/**
 * @interface IHeuristicProvider
 * @brief Interface for objects that provide heuristic control over agents or actuators.
 *
 * The IHeuristicProvider interface allows objects (such as agents or actuators) to fill out the
 * `FActionBuffers` data structure with heuristic-based actions. This interface is used to provide manual
 * or rule-based decisions instead of using a machine learning model for decision making.
 */
UINTERFACE(MinimalAPI)
class UHeuristicProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * @class IHeuristicProvider
 * @brief Interface that provides a heuristic method for determining agent or actuator actions.
 *
 * The IHeuristicProvider interface defines a method for filling the `FActionBuffers` data structure
 * with heuristic actions. Implementations of this interface are expected to consistently place actions
 * into the appropriate positions within the `FActionBuffers`, ensuring that the actions align with
 * the expected behavior of the agent or actuator.
 */
class IHeuristicProvider
{
	GENERATED_BODY()

public:
	/**
	 * @brief Populates the `FActionBuffers` structure with heuristic-based actions.
	 *
	 * This method is called on objects that implement heuristic control. The implementing class is responsible
	 * for filling out the `FActionBuffers` data structure with appropriate actions. It is crucial to ensure
	 * that the placement of actions within the buffer is consistent, as improper alignment can lead to
	 * incorrect behavior in the agent or actuator.
	 *
	 * @param ActionBuffersOut The `FActionBuffers` data structure to be filled with heuristic-based actions.
	 */
	virtual void Heuristic(const FActionBuffers& ActionBuffersOut) = 0;
};
