#pragma once

#include "CoreMinimal.h"
#include "google/protobuf/repeated_field.h"
#include "UObject/ObjectMacros.h"

/**
 * @class ObservationWriter
 * @brief A utility class for writing observation data in reinforcement learning environments.
 *
 * The `ObservationWriter` class allows sensors and other data sources to write observations
 * into a Protobuf RepeatedField or float arrays. It provides methods for writing individual elements,
 * vectors, and quaternions. The class also supports reshaping multi-dimensional observation data.
 */
class ObservationWriter
{
private:
	/** Pointer to the Protobuf repeated field where the data will be written. */
	google::protobuf::RepeatedField<float>* Data;

	/** Offset for writing data into the target buffer. */
	int Offset;

	/** Batch index used when writing to batch-based observation data. */
	int Batch;

	/** Shape of the observations being written. */
	FInplaceArray<int32> Shape;

public:
	/**
	 * @brief Default constructor.
	 *
	 * Initializes the `ObservationWriter` without any data target. Use `SetTarget` to define where the data will be written.
	 */
	ObservationWriter()
		: Data(nullptr), Offset(0), Batch(0) {}

	/**
	 * @brief Sets the target data array and the observation shape for writing.
	 *
	 * This method sets the target Protobuf repeated field and defines the shape of the observations.
	 * The offset specifies where in the buffer the writing should begin.
	 *
	 * @param InData Pointer to the Protobuf repeated field where the observation data will be written.
	 * @param InShape The shape of the observation, represented as a fixed-size array.
	 * @param InOffset The offset within the target buffer to begin writing data.
	 */
	void SetTarget(google::protobuf::RepeatedField<float>* InData, const FInplaceArray<int32>& InShape, int InOffset)
	{
		Data = InData;
		Shape = InShape;
		Offset = InOffset;
		Batch = 0;
	}

	/**
	 * @brief 1D write access operator.
	 *
	 * This operator provides 1D access to the underlying observation data, allowing values to be written
	 * to the specified index in the data buffer.
	 *
	 * @param Index The index in the buffer where the value should be written.
	 * @return Reference to the float value at the specified index.
	 */
	float& operator[](int Index)
	{
		check(Data != nullptr);
		return (*Data)[Index + Offset];
	}

	/**
	 * @brief 2D write access operator.
	 *
	 * This operator provides 2D access to the underlying observation data, useful for writing data
	 * with channel and width dimensions.
	 *
	 * @param Ch The channel index.
	 * @param W The width index.
	 * @return Reference to the float value at the specified location.
	 */
	float& operator()(int Ch, int W)
	{
		check(Data != nullptr);
		return (*Data)[Ch * Shape[Shape.GetLength() - 1] + W];
	}

	/**
	 * @brief 3D write access operator.
	 *
	 * This operator provides 3D access to the underlying observation data, allowing values to be written
	 * at specific channel, height, and width indices. Bounds checking is performed for the provided indices.
	 *
	 * @param Ch The channel index.
	 * @param H The height index.
	 * @param W The width index.
	 * @return Reference to the float value at the specified location.
	 */
	float& operator()(int Ch, int H, int W)
	{
		check(Data != nullptr);

		if (H < 0 || H >= Shape[1])
		{
			UE_LOG(LogTemp, Error, TEXT("Height value %d must be in range [0, %d]"), H, Shape[1] - 1);
			checkNoEntry();
		}

		if (W < 0 || W >= Shape[2])
		{
			UE_LOG(LogTemp, Error, TEXT("Width value %d must be in range [0, %d]"), W, Shape[2] - 1);
			checkNoEntry();
		}

		if (Ch < 0 || Ch >= Shape[0])
		{
			UE_LOG(LogTemp, Error, TEXT("Channel value %d must be in range [0, %d]"), Ch, Shape[0] - 1);
			checkNoEntry();
		}

		int Index = Ch * Shape[1] * Shape[2] + H * Shape[2] + W;
		return (*Data)[Index];
	}

	/**
	 * @brief Writes a list of float data into the observation buffer.
	 *
	 * This method adds a list of float values into the buffer at the specified offset.
	 *
	 * @param InData The array of float values to write.
	 * @param WriteOffset Optional offset specifying where to start writing the data.
	 */
	void AddList(const TArray<float>& InData, int WriteOffset = 0)
	{
		check(Data != nullptr);

		int TotalSize = Offset + WriteOffset + InData.Num();
		if (Data->size() < TotalSize)
		{
			Data->Resize(TotalSize, 0.0f); // Ensure Data has enough capacity
		}

		for (int Index = 0; Index < InData.Num(); Index++)
		{
			Data->Set(Index + Offset + WriteOffset, InData[Index]);
		}
	}

	/**
	 * @brief Writes a 3D vector into the observation buffer.
	 *
	 * This method adds the components of a 3D vector (FVector) into the buffer.
	 *
	 * @param Vec The vector to write into the buffer.
	 * @param WriteOffset Optional offset specifying where to start writing the vector.
	 */
	void Add(const FVector& Vec, int WriteOffset = 0)
	{
		check(Data != nullptr);

		int TotalSize = Offset + WriteOffset + 3;
		if (Data->size() < TotalSize)
		{
			Data->Resize(TotalSize, 0.0f); // Ensure Data has enough capacity
		}

		Data->Set(Offset + WriteOffset + 0, Vec.X);
		Data->Set(Offset + WriteOffset + 1, Vec.Y);
		Data->Set(Offset + WriteOffset + 2, Vec.Z);
	}

	/**
	 * @brief Writes a 4D vector into the observation buffer.
	 *
	 * This method adds the components of a 4D vector (FVector4) into the buffer.
	 *
	 * @param Vec The 4D vector to write into the buffer.
	 * @param WriteOffset Optional offset specifying where to start writing the vector.
	 */
	void Add(const FVector4& Vec, int WriteOffset = 0)
	{
		check(Data != nullptr);

		int TotalSize = Offset + WriteOffset + 4;
		if (Data->size() < TotalSize)
		{
			Data->Resize(TotalSize, 0.0f); // Ensure Data has enough capacity
		}

		Data->Set(Offset + WriteOffset + 0, Vec.X);
		Data->Set(Offset + WriteOffset + 1, Vec.Y);
		Data->Set(Offset + WriteOffset + 2, Vec.Z);
		Data->Set(Offset + WriteOffset + 3, Vec.W); // Corrected to Vec.W
	}

	/**
	 * @brief Writes a quaternion into the observation buffer.
	 *
	 * This method adds the components of a quaternion (FQuat) into the buffer.
	 *
	 * @param Quat The quaternion to write into the buffer.
	 * @param WriteOffset Optional offset specifying where to start writing the quaternion.
	 */
	void Add(const FQuat& Quat, int WriteOffset = 0)
	{
		check(Data != nullptr);

		int TotalSize = Offset + WriteOffset + 4;
		if (Data->size() < TotalSize)
		{
			Data->Resize(TotalSize, 0.0f); // Ensure Data has enough capacity
		}

		Data->Set(Offset + WriteOffset + 0, Quat.X);
		Data->Set(Offset + WriteOffset + 1, Quat.Y);
		Data->Set(Offset + WriteOffset + 2, Quat.Z);
		Data->Set(Offset + WriteOffset + 3, Quat.W);
	}
};
