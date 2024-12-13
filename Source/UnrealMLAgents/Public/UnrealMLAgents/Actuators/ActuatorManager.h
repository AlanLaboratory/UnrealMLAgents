#pragma once

#include "CoreMinimal.h"
#include "UnrealMLAgents/Actuators/IActuator.h"
#include "UnrealMLAgents/Actuators/IActionReceiver.h"
#include "ActuatorDiscreteActionMask.h"
#include "ActuatorManager.generated.h"

/**
 * @class UActuatorManager
 * @brief Manages the delegation of events, action buffers, and action masks for a list of IActuators.
 *
 * This class handles the initialization, execution, and coordination of all the actuators within the UnrealMLAgents
 * system. It also manages action buffers and action masks for actuators, ensuring that agents' actions are correctly
 * applied and received.
 */
UCLASS()
class UNREALMLAGENTS_API UActuatorManager : public UObject
{
	GENERATED_BODY()

public:
	/**
	 * @brief Initializes the actuator manager with a preset capacity.
	 *
	 * @param Capacity The number of actuators to allocate space for initially.
	 */
	void Initialize(int32 Capacity = 0);

	// Getters

	/**
	 * @brief Returns the total number of discrete branches (actions) across all actuators.
	 *
	 * @return The sum of the discrete branch sizes for all actuators.
	 */
	int32 GetSumOfDiscreteBranchSizes() const { return SumOfDiscreteBranchSizes; }

	/**
	 * @brief Returns the total number of discrete actions across all actuators.
	 *
	 * @return The number of discrete actions across all actuators.
	 */
	int32 GetNumDiscreteActions() const { return NumDiscreteActions; }

	/**
	 * @brief Returns the total number of continuous actions across all actuators.
	 *
	 * @return The number of continuous actions across all actuators.
	 */
	int32 GetNumContinuousActions() const { return NumContinuousActions; }

	/**
	 * @brief Returns the total number of actions (both continuous and discrete).
	 *
	 * @return The sum of continuous and discrete actions.
	 */
	int32 GetTotalNumberOfActions() const { return NumContinuousActions + NumDiscreteActions; }

	/**
	 * @brief Retrieves the discrete action mask managed by this class.
	 *
	 * @return The reference to the discrete action mask.
	 */
	const UActuatorDiscreteActionMask& GetDiscreteActionMask() const;

	/**
	 * @brief Retrieves the stored action buffers for the actuators managed by this class.
	 *
	 * @return A reference to the action buffers.
	 */
	FActionBuffers& GetStoredActions() { return StoredActions; }

	// Methods

	/**
	 * @brief Prepares the actuators for execution by validating and sorting them.
	 */
	void ReadyActuatorsForExecution();

	/**
	 * @brief Updates the stored action buffers with the actions provided by the actuators.
	 *
	 * @param Actions The action buffers containing the actions for all actuators.
	 */
	void UpdateActions(const FActionBuffers& Actions);

	/**
	 * @brief Combines the action specifications (continuous and discrete) of all actuators into one.
	 *
	 * @return The combined action specification for all actuators.
	 */
	FActionSpec GetCombinedActionSpec();

	/**
	 * @brief Writes the action mask by resetting and applying new masks from each actuator.
	 */
	void WriteActionMask();

	/**
	 * @brief Applies heuristic actions to the actuators based on the provided action buffers.
	 *
	 * @param ActionBuffersOut The buffers where the heuristic actions will be written.
	 */
	void ApplyHeuristic(const FActionBuffers& ActionBuffersOut);

	/**
	 * @brief Executes the actions for each actuator.
	 */
	void ExecuteActions();

	/**
	 * @brief Resets the data of all actuators and clears the stored action buffers.
	 */
	void ResetData();

	/**
	 * @brief Adds an actuator to the manager.
	 *
	 * @param Item The actuator to be added.
	 */
	void Add(const TScriptInterface<IActuator>& Item);

	/**
	 * @brief Clears all actuators from the manager.
	 */
	void Clear();

	/**
	 * @brief Checks if a specific actuator is contained within the manager.
	 *
	 * @param Item The actuator to check.
	 * @return True if the actuator is found, false otherwise.
	 */
	bool Contains(const TScriptInterface<IActuator>& Item) const;

	/**
	 * @brief Copies the actuators to another array.
	 *
	 * @param OutArray The destination array to copy the actuators into.
	 * @param ArrayIndex The starting index in the destination array.
	 */
	void CopyTo(TArray<TScriptInterface<IActuator>>& OutArray, int32 ArrayIndex) const;

	/**
	 * @brief Removes an actuator from the manager.
	 *
	 * @param Item The actuator to be removed.
	 * @return True if the actuator was removed, false otherwise.
	 */
	bool Remove(const TScriptInterface<IActuator>& Item);

	/**
	 * @brief Gets the total number of actuators managed by this object.
	 *
	 * @return The number of actuators.
	 */
	int32 Count() const;

	/**
	 * @brief Checks if the list of actuators is read-only.
	 *
	 * @return True if the list is read-only, false otherwise.
	 */
	bool IsReadOnly() const;

	/**
	 * @brief Finds the index of a specific actuator in the list.
	 *
	 * @param Item The actuator to locate.
	 * @return The index of the actuator if found, otherwise -1.
	 */
	int32 IndexOf(const TScriptInterface<IActuator>& Item) const;

	/**
	 * @brief Inserts an actuator at a specific index.
	 *
	 * @param Index The index at which to insert the actuator.
	 * @param Item The actuator to insert.
	 */
	void Insert(int32 Index, const TScriptInterface<IActuator>& Item);

	/**
	 * @brief Removes an actuator at a specific index.
	 *
	 * @param Index The index from which to remove the actuator.
	 */
	void RemoveAt(int32 Index);

	/**
	 * @brief Retrieves the actuator at a specified index.
	 *
	 * @param Index The index of the actuator to retrieve.
	 * @return The actuator at the specified index.
	 */
	TScriptInterface<IActuator> Get(int32 Index) const;

	/**
	 * @brief Sets the actuator at a specified index.
	 *
	 * @param Index The index where the actuator will be set.
	 * @param Value The actuator to set at the specified index.
	 */
	void Set(int32 Index, const TScriptInterface<IActuator>& Value);

	/**
	 * @brief Index operator to get an actuator at a specific index.
	 *
	 * @param Index The index of the actuator to retrieve.
	 * @return The actuator at the specified index.
	 */
	TScriptInterface<IActuator> operator[](int32 Index) const;

	/**
	 * @brief Index operator to set an actuator at a specific index.
	 *
	 * @param Index The index where the actuator will be set.
	 * @return A reference to the actuator at the specified index.
	 */
	TScriptInterface<IActuator>& operator[](int32 Index);

	/**
	 * @brief Creates a constant iterator for the actuators in the manager.
	 *
	 * @return A constant iterator over the actuators.
	 */
	TArray<TScriptInterface<IActuator>>::TConstIterator CreateConstIterator() const;

	/**
	 * @brief Creates an iterator for the actuators in the manager.
	 *
	 * @return An iterator over the actuators.
	 */
	TArray<TScriptInterface<IActuator>>::TIterator CreateIterator();

private:
	/** @brief The actuators managed by this object. */
	UPROPERTY()
	TArray<TScriptInterface<IActuator>> Actuators;

	/** @brief Discrete action mask managed by this class for actuators with discrete actions. */
	UPROPERTY()
	UActuatorDiscreteActionMask* DiscreteActionMask;

	/** @brief Combined action specification for all actuators. */
	UPROPERTY()
	FActionSpec CombinedActionSpec;

	/** @brief The currently stored action buffers for the actuators. */
	UPROPERTY()
	FActionBuffers StoredActions;

	/** @brief Flag to indicate if actuators are ready for execution. */
	bool bReadyForExecution;

	/** @brief Sum of all discrete branches for all actuators. */
	int32 SumOfDiscreteBranchSizes;

	/** @brief Number of discrete actions across all actuators. */
	int32 NumDiscreteActions;

	/** @brief Number of continuous actions across all actuators. */
	int32 NumContinuousActions;

	// Helper methods

	/**
	 * @brief Prepares the actuators for execution by validating and sorting them.
	 *
	 * @param InActuators The actuators to prepare for execution.
	 * @param InNumContinuousActions Total number of continuous actions across all actuators.
	 * @param InSumOfDiscreteBranchSizes Sum of all discrete branches across all actuators.
	 * @param InNumDiscreteBranches Number of discrete branches across all actuators.
	 */
	void ReadyActuatorsForExecution(const TArray<TScriptInterface<IActuator>>& InActuators,
		int32 InNumContinuousActions, int32 InSumOfDiscreteBranchSizes, int32 InNumDiscreteBranches);

	/**
	 * @brief Combines the action specifications of all actuators into a single specification.
	 *
	 * @param Actuators The actuators whose action specifications will be combined.
	 * @return The combined action specification.
	 */
	static FActionSpec CombineActionSpecs(const TArray<TScriptInterface<IActuator>>& Actuators);

	/**
	 * @brief Validates that all actuators have unique names and sorts them.
	 */
	void ValidateActuators();

	/**
	 * @brief Sorts the actuators by name to ensure deterministic execution.
	 *
	 * @param InActuators The actuators to sort.
	 */
	void SortActuators(TArray<TScriptInterface<IActuator>>& InActuators);

	/**
	 * @brief Updates the action buffer for a specific type of action.
	 *
	 * @tparam T The type of action (continuous or discrete).
	 * @param SourceActionBuffer The source action buffer to update from.
	 * @param Destination The destination action buffer to update.
	 */
	template <typename T>
	static void UpdateActionArray(const FActionSegment<T>& SourceActionBuffer, FActionSegment<T>& Destination);

	/**
	 * @brief Adds an actuator's action buffer sizes to the total.
	 *
	 * @param ActuatorItem The actuator to add.
	 */
	void AddToBufferSizes(const TScriptInterface<IActuator>& ActuatorItem);

	/**
	 * @brief Subtracts an actuator's action buffer sizes from the total.
	 *
	 * @param ActuatorItem The actuator to subtract.
	 */
	void SubtractFromBufferSizes(const TScriptInterface<IActuator>& ActuatorItem);

	/**
	 * @brief Clears the stored action buffer sizes.
	 */
	void ClearBufferSizes();

	/**
	 * @brief Adds multiple actuators to the manager.
	 *
	 * @param InActuators The actuators to add.
	 */
	void AddActuators(const TArray<TScriptInterface<IActuator>>& InActuators);
};
