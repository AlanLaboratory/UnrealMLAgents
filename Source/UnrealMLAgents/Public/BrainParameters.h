#pragma once

#include "CoreMinimal.h"
#include "ActionSpec.h"
#include "BrainParameters.generated.h"

/**
 * @struct FBrainParameters
 * @brief Holds information about the brain of an agent, defining the inputs and outputs of the decision process.
 *
 * This structure contains details about the agent's observations, how actions are defined, and how they are stacked
 * across frames. It also includes utilities for cloning the brain parameters and managing its action specifications.
 */
USTRUCT(BlueprintType)
struct UNREALMLAGENTS_API FBrainParameters
{
	GENERATED_BODY()

public:
	/**
	 * @brief The number of vector observations for the agent.
	 *
	 * This represents the size of the observation vector that the agent collects during each step.
	 * @note This size should be sufficient to capture all necessary state information.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brain Parameters")
	int32 VectorObservationSize = 1;

	/**
	 * @brief The number of stacked vector observations across multiple frames.
	 *
	 * Stacking observations means concatenating observations from multiple frames to provide
	 * temporal context to the agent. This field controls how many frames are stacked.
	 *
	 * @note The value is clamped between 1 and 50.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brain Parameters", meta = (ClampMin = "1", ClampMax = "50"))
	int32 NumStackedVectorObservations = 1;

	/**
	 * @brief The specification of the actions for the agent.
	 *
	 * This field defines the structure of the action space, whether continuous or discrete,
	 * and the number of possible actions in each branch.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brain Parameters")
	FActionSpec ActionSpec;

	/**
	 * @brief Describes what each action in the action space corresponds to.
	 *
	 * This is an array of strings, each describing the purpose or meaning of the corresponding action.
	 * For example, in a discrete action space, "Move Forward" might correspond to one action branch.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brain Parameters")
	TArray<FString> VectorActionDescriptions;

	/** @brief Flag indicating if the brain parameters have been upgraded with the ActionSpec. */
	bool bHasUpgradedBrainParametersWithActionSpec;

	/**
	 * @brief Creates a deep clone of the FBrainParameters struct.
	 *
	 * This method allows the entire brain parameter object to be duplicated, preserving
	 * all the observation and action configuration.
	 *
	 * @return A cloned FBrainParameters object with identical properties.
	 */
	FBrainParameters Clone() const
	{
		FBrainParameters ClonedStruct;
		ClonedStruct.VectorObservationSize = this->VectorObservationSize;
		ClonedStruct.NumStackedVectorObservations = this->NumStackedVectorObservations;
		ClonedStruct.ActionSpec = this->ActionSpec;
		ClonedStruct.VectorActionDescriptions = this->VectorActionDescriptions;
		ClonedStruct.bHasUpgradedBrainParametersWithActionSpec = this->bHasUpgradedBrainParametersWithActionSpec;
		return ClonedStruct;
	}
};
