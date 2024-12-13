#pragma once

#include "CoreMinimal.h"
#include "DimensionProperty.generated.h"

/**
 * @enum EDimensionProperty
 * @brief Specifies properties of dimensions for observations in the reinforcement learning environment.
 *
 * The `EDimensionProperty` enum is used to describe how certain dimensions of observations should be treated,
 * whether they are suitable for convolution, unordered, or have variable sizes. This information is useful when
 * determining how to process observations in neural networks.
 */
UENUM(BlueprintType)
enum class EDimensionProperty : uint8
{
	/**
	 * @brief No properties specified for this dimension.
	 *
	 * This is the default value when no specific property is assigned to the observation dimension.
	 */
	Unspecified = 0 UMETA(DisplayName = "Unspecified"),

	/**
	 * @brief No special property for this dimension.
	 *
	 * The observation in this dimension can be processed with fully connected layers,
	 * meaning it has no spatial or ordering constraints.
	 */
	None = 1 UMETA(DisplayName = "None"),

	/**
	 * @brief The dimension is suitable for convolutions.
	 *
	 * This property indicates that the observation in this dimension has some form of translational
	 * equivariance, making it appropriate for convolutional neural networks (CNNs).
	 */
	TranslationalEquivariance = 2 UMETA(DisplayName = "Translational Equivariance"),

	/**
	 * @brief The dimension can have a variable number of unordered observations.
	 *
	 * This property suggests that the number of observations in this dimension can vary, and
	 * the observations are unordered. This can be useful for variable-length sequences or sets.
	 */
	VariableSize = 4 UMETA(DisplayName = "Variable Size")
};
