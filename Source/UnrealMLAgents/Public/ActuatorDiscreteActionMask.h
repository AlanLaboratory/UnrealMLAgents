#pragma once

#include "CoreMinimal.h"
#include "IActuator.h"
#include "IDiscreteActionMask.h"
#include "ActuatorDiscreteActionMask.generated.h"

/**
 * @class UActuatorDiscreteActionMask
 * @brief Manages the action mask for discrete actions in the UnrealMLAgents system.
 *
 * This class is responsible for enabling or disabling specific discrete actions within the action space
 * of an agent's actuators. The action mask is used to restrict or allow actions an agent can perform
 * during training or inference.
 */
UCLASS()
class UNREALMLAGENTS_API UActuatorDiscreteActionMask : public UObject, public IDiscreteActionMask
{
	GENERATED_BODY()

public:
	/** @brief Offset used to identify the starting index of the current branch in the action space. */
	int32 CurrentBranchOffset;

	/**
	 * @brief Initializes the action mask for a set of actuators and the associated branches and action sizes.
	 *
	 * @param InActuators The actuators whose action space is being managed.
	 * @param InSumOfDiscreteBranchSizes The total number of discrete actions across all branches.
	 * @param InNumDiscreteBranches The number of discrete branches in the action space.
	 * @param InBranchSizes Optional array representing the size of each branch.
	 */
	void Initialize(const TArray<TScriptInterface<IActuator>>& InActuators, int32 InSumOfDiscreteBranchSizes,
		int32 InNumDiscreteBranches, const TArray<int32>& InBranchSizes = TArray<int32>())
	{
		Actuators = InActuators;
		SumOfDiscreteBranchSizes = InSumOfDiscreteBranchSizes;
		NumBranches = InNumDiscreteBranches;
		BranchSizes = InBranchSizes;
	}

	/**
	 * @brief Enables or disables a specific action within a branch.
	 *
	 * @param Branch The index of the branch in which the action resides.
	 * @param ActionIndex The index of the action within the branch.
	 * @param bIsEnabled Boolean indicating whether the action is enabled or disabled.
	 */
	void SetActionEnabled(int32 Branch, int32 ActionIndex, bool bIsEnabled)
	{
		LazyInitialize();
		CurrentMask[ActionIndex + StartingActionIndices[CurrentBranchOffset + Branch]] = !bIsEnabled;
	}

	/**
	 * @brief Retrieves the current action mask.
	 *
	 * @return A boolean array representing the current action mask.
	 * True values indicate actions that are masked (disabled), and false values indicate enabled actions.
	 */
	TArray<bool> GetMask() const { return CurrentMask; }

	/**
	 * @brief Resets the action mask, re-enabling all previously masked actions.
	 *
	 * This method clears the current mask, effectively resetting all actions to enabled.
	 */
	void ResetMask()
	{
		if (CurrentMask.Num() > 0)
		{
			CurrentMask.Init(false, CurrentMask.Num());
		}
	}

private:
	/** @brief The actuators that are controlled by this action mask. */
	UPROPERTY()
	TArray<TScriptInterface<IActuator>> Actuators;

	/** @brief Array storing the starting indices for each branch in the action space. */
	TArray<int32> StartingActionIndices;

	/** @brief Array representing the sizes of each branch in the action space. */
	TArray<int32> BranchSizes;

	/** @brief The current mask applied to the actions, where true means masked (disabled). */
	TArray<bool> CurrentMask;

	/** @brief Total number of discrete actions across all branches. */
	int32 SumOfDiscreteBranchSizes;

	/** @brief Total number of discrete branches in the action space. */
	int32 NumBranches;

	/**
	 * @brief Lazily initializes the branch sizes, starting indices, and action mask.
	 *
	 * This method ensures that the branch sizes, starting indices, and mask arrays are properly initialized
	 * before being used, avoiding unnecessary allocations until they are needed.
	 */
	void LazyInitialize()
	{
		if (BranchSizes.Num() == 0)
		{
			BranchSizes.SetNum(NumBranches);
			int32 Start = 0;
			for (const auto& Actuator : Actuators)
			{
				const TArray<int32>& CopyBranchSizes = Actuator->GetActionSpec().BranchSizes;
				for (int32 Size : CopyBranchSizes)
				{
					BranchSizes[Start++] = Size;
				}
			}
		}

		if (CurrentMask.Num() == 0)
		{
			CurrentMask.SetNum(SumOfDiscreteBranchSizes);
		}

		if (StartingActionIndices.Num() == 0)
		{
			StartingActionIndices = CumSum(BranchSizes);
		}
	}

	/**
	 * @brief Computes the cumulative sum of an array.
	 *
	 * @param InputArray The input array to compute the cumulative sum for.
	 * @return An array containing the cumulative sum of the input array.
	 */
	TArray<int32> CumSum(const TArray<int32>& InputArray)
	{
		TArray<int32> Result;
		Result.SetNum(InputArray.Num() + 1);
		Result[0] = 0;
		for (int32 i = 0; i < InputArray.Num(); ++i)
		{
			Result[i + 1] = Result[i] + InputArray[i];
		}
		return Result;
	}

	/**
	 * @brief Asserts that the action mask is valid, ensuring no branch is fully masked.
	 *
	 * This method checks each branch of the action space to verify that not all actions within any branch
	 * are masked, which would result in an invalid action space configuration.
	 */
	void AssertMask()
	{
		for (int32 BranchIndex = 0; BranchIndex < NumBranches; ++BranchIndex)
		{
			if (AreAllActionsMasked(BranchIndex))
			{
				UE_LOG(LogTemp, Error, TEXT("Invalid Action Masking: All the actions of branch %d are masked."),
					BranchIndex);
			}
		}
	}

	/**
	 * @brief Checks if all actions within a specific branch are masked.
	 *
	 * @param Branch The index of the branch to check.
	 * @return True if all actions in the branch are masked, false otherwise.
	 */
	bool AreAllActionsMasked(int32 Branch)
	{
		if (CurrentMask.Num() == 0)
		{
			return false;
		}

		int32 Start = StartingActionIndices[Branch];
		int32 End = StartingActionIndices[Branch + 1];
		for (int32 i = Start; i < End; ++i)
		{
			if (!CurrentMask[i])
			{
				return false;
			}
		}

		return true;
	}
};
