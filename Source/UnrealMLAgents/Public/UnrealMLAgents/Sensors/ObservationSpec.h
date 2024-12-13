#pragma once

#include "CoreMinimal.h"
#include "InplaceArray.h"
#include "UnrealMLAgents/DimensionProperty.h"
#include "UnrealMLAgents/Sensors/ObservationType.h"
#include "ObservationSpec.generated.h"

/**
 * @struct FObservationSpec
 * @brief Defines the specification of observations produced by sensors in reinforcement learning environments.
 *
 * The `FObservationSpec` struct describes the shape, properties, and type of observations that a sensor generates.
 * It is used to inform the learning model about the structure of the input data, ensuring proper interpretation
 * of the observations by the learning algorithm.
 */
USTRUCT(BlueprintType)
struct UNREALMLAGENTS_API FObservationSpec
{
	GENERATED_BODY()

private:
	/** The shape of the observations (e.g., [Height, Width, Channels] for an image). */
	FInplaceArray<int32> Shape;

	/** Properties of each dimension of the observation, such as whether it's suitable for convolutions. */
	FInplaceArray<EDimensionProperty> DimensionProperties;

	/** The type of the observation, such as whether it's generic or related to a goal. */
	EObservationType ObservationType;

public:
	/**
	 * @brief Default constructor.
	 */
	FObservationSpec() {}

	/**
	 * @brief Constructs an observation spec with the provided shape, dimension properties, and observation type.
	 *
	 * @param InShape The shape of the observation.
	 * @param InDimensionProperties The properties of each dimension in the observation.
	 * @param InObservationType The type of the observation (default is generic).
	 */
	FObservationSpec(FInplaceArray<int32> InShape, FInplaceArray<EDimensionProperty> InDimensionProperties,
		EObservationType InObservationType = EObservationType::Default)
		: Shape(InShape), DimensionProperties(InDimensionProperties), ObservationType(InObservationType)
	{
		check(Shape.GetLength() == DimensionProperties.GetLength());
	}

	/**
	 * @brief Gets the shape of the observation.
	 *
	 * @return The shape of the observation as an `FInplaceArray<int32>`.
	 */
	const FInplaceArray<int32>& GetShape() const { return Shape; }

	/**
	 * @brief Gets the properties of each dimension in the observation.
	 *
	 * @return The dimension properties as an `FInplaceArray<EDimensionProperty>`.
	 */
	const FInplaceArray<EDimensionProperty>& GetDimensionProperties() const { return DimensionProperties; }

	/**
	 * @brief Gets the type of the observation.
	 *
	 * @return The type of the observation as an `EObservationType`.
	 */
	EObservationType GetObservationType() const { return ObservationType; }

	/**
	 * @brief Gets the number of dimensions (rank) of the observation.
	 *
	 * @return The number of dimensions (rank) of the observation.
	 */
	int32 GetRank() const { return Shape.GetLength(); }

	/**
	 * @brief Constructs an observation spec for 1-D vector observations.
	 *
	 * This helper function is used for sensors that generate 1-dimensional observations, such as velocity vectors.
	 *
	 * @param Length The length of the vector.
	 * @param InObservationType The type of the observation (default is generic).
	 * @return A 1-D vector observation spec.
	 */
	static FObservationSpec Vector(int32 Length, EObservationType InObservationType = EObservationType::Default)
	{
		return FObservationSpec(FInplaceArray<int32>(Length),
			FInplaceArray<EDimensionProperty>(EDimensionProperty::None), InObservationType);
	}

	/**
	 * @brief Constructs an observation spec for variable-length observations.
	 *
	 * This helper function is used for sensors that generate variable-length observations, where the number
	 * of observations may change during the simulation.
	 *
	 * @param ObsSize The size of each individual observation.
	 * @param MaxNumObs The maximum number of observations that can be generated.
	 * @return A variable-length observation spec.
	 */
	static FObservationSpec VariableLength(int32 ObsSize, int32 MaxNumObs)
	{
		return FObservationSpec(FInplaceArray<int32>(ObsSize, MaxNumObs),
			FInplaceArray<EDimensionProperty>(EDimensionProperty::VariableSize, EDimensionProperty::None));
	}

	/**
	 * @brief Constructs an observation spec for visual-like observations (e.g., images).
	 *
	 * This helper function is used for sensors that generate visual data, such as RGB images or depth maps.
	 * The dimensions are typically [Channels, Height, Width], and the dimension properties specify that
	 * the data is suitable for convolutions (i.e., translationally equivariant).
	 *
	 * @param Channels The number of channels (e.g., 3 for RGB images).
	 * @param Height The height of the image.
	 * @param Width The width of the image.
	 * @param InObservationType The type of the observation (default is generic).
	 * @return A visual observation spec.
	 */
	static FObservationSpec Visual(
		int32 Channels, int32 Height, int32 Width, EObservationType InObservationType = EObservationType::Default)
	{
		return FObservationSpec(FInplaceArray<int32>(Channels, Height, Width),
			FInplaceArray<EDimensionProperty>(EDimensionProperty::None, EDimensionProperty::TranslationalEquivariance,
				EDimensionProperty::TranslationalEquivariance),
			InObservationType);
	}
};
