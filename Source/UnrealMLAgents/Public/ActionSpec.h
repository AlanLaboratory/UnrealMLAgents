#pragma once

#include "CoreMinimal.h"
#include "ActionSpec.generated.h"

/**
 * @struct FActionSpec
 * @brief Defines the structure of the actions to be used by the Actuator system.
 *
 * The ActionSpec defines both continuous and discrete actions that can be performed by an agent.
 * It allows specifying either continuous actions or discrete branches of actions, but not both simultaneously.
 */
USTRUCT(BlueprintType)
struct FActionSpec
{
	GENERATED_BODY()

public:
	/** @brief The number of continuous actions that an agent can take. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionSpec", meta = (AllowPrivateAccess = "true"))
	int32 NumContinuousActions;

	/** @brief An array representing the branch sizes for discrete actions.
	 * Each index in this array represents the number of possible discrete actions for that branch. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActionSpec")
	TArray<int32> BranchSizes;

	/**
	 * @brief Default constructor initializing the continuous actions to 0.
	 */
	FActionSpec() : NumContinuousActions(0) {}

	/**
	 * @brief Constructor with parameters for initializing continuous and discrete actions.
	 *
	 * @param InNumContinuousActions The number of continuous actions.
	 * @param InBranchSizes The array representing the sizes of each discrete branch.
	 */
	FActionSpec(int32 InNumContinuousActions, const TArray<int32>& InBranchSizes)
		: NumContinuousActions(InNumContinuousActions), BranchSizes(InBranchSizes)
	{
	}

	/**
	 * @brief Creates a Continuous ActionSpec with the number of continuous actions available.
	 *
	 * @param NumActions The number of continuous actions available.
	 * @return A Continuous ActionSpec initialized with the number of actions.
	 */
	static FActionSpec MakeContinuous(int32 NumActions) { return FActionSpec(NumActions, TArray<int32>()); }

	/**
	 * @brief Creates a Discrete ActionSpec with the array of branch sizes representing the action space.
	 *
	 * @param InBranchSizes The array of branch sizes for the discrete actions.
	 * @return A Discrete ActionSpec initialized with the array of branch sizes.
	 */
	static FActionSpec MakeDiscrete(const TArray<int32>& InBranchSizes) { return FActionSpec(0, InBranchSizes); }

	/**
	 * @brief Checks that the ActionSpec uses either all continuous or all discrete actions.
	 *
	 * @remarks This function ensures that mixed action spaces (both continuous and discrete actions)
	 * are not supported. ActionSpecs must be either fully continuous or fully discrete.
	 */
	void CheckAllContinuousOrDiscrete() const
	{
		if (NumContinuousActions > 0 && BranchSizes.Num() > 0)
		{
			UE_LOG(LogTemp, Error,
				TEXT("Action spaces with both continuous and discrete actions are not supported. "
					 "ActionSpecs must be all continuous or all discrete."));
		}
	}

	/**
	 * @brief Combines a list of ActionSpecs into a single ActionSpec.
	 *
	 * This function aggregates multiple ActionSpecs into a single one by summing the number of continuous actions
	 * and combining the branch sizes for discrete actions.
	 *
	 * @param Specs The list of ActionSpecs to combine.
	 * @return A combined ActionSpec that represents the aggregate of the provided specs.
	 */
	static FActionSpec Combine(const TArray<FActionSpec>& Specs)
	{
		int32 TotalContinuous = 0;
		int32 TotalDiscrete = 0;
		for (const FActionSpec& Spec : Specs)
		{
			TotalContinuous += Spec.NumContinuousActions;
			TotalDiscrete += Spec.BranchSizes.Num();
		}

		if (TotalDiscrete <= 0)
		{
			return MakeContinuous(TotalContinuous);
		}

		TArray<int32> CombinedBranchSizes;
		CombinedBranchSizes.SetNumUninitialized(TotalDiscrete);
		int32 Offset = 0;
		for (const FActionSpec& Spec : Specs)
		{
			if (Spec.BranchSizes.Num() > 0)
			{
				const int32 BranchSizeCount = Spec.BranchSizes.Num();
				FMemory::Memcpy(CombinedBranchSizes.GetData() + Offset, Spec.BranchSizes.GetData(),
					BranchSizeCount * sizeof(int32));
				Offset += BranchSizeCount;
			}
		}

		return FActionSpec(TotalContinuous, CombinedBranchSizes);
	}

	/**
	 * @brief Returns the total number of discrete actions by summing the branch sizes.
	 *
	 * @return The sum of all the branch sizes for discrete actions.
	 */
	int32 GetSumOfDiscreteBranchSizes() const
	{
		int32 Sum = 0;
		for (int32 BranchSize : BranchSizes)
		{
			Sum += BranchSize;
		}
		return Sum;
	}

	/**
	 * @brief Returns the number of discrete actions (branches).
	 *
	 * @return The number of branches for discrete actions.
	 */
	int32 GetNumDiscreteActions() const { return BranchSizes.Num(); }
};
