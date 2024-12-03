#pragma once

#include "CoreMinimal.h"

/**
 * @struct FActionSegment
 * @brief A template-based data structure that allows access to a segment of an underlying array without copying or
 * allocating sub-arrays.
 *
 * The action segment is defined by an offset and length into the original array. This is useful for avoiding
 * performance overhead when dealing with large arrays or when working with segments of arrays for specific actions in
 * the UnrealMLAgents system.
 *
 * @tparam T The type of object stored in the underlying array.
 */
template <typename T> struct FActionSegment
{
public:
	/// The zero-based offset into the original array at which this segment starts.
	int32 Offset;

	/// The number of items this segment can access in the underlying array.
	int32 Length;

	/// A shared pointer to the underlying array of type T.
	TSharedPtr<TArray<T>> Array;

	/// Static member representing an empty ActionSegment.
	static FActionSegment<T> Empty;

	/**
	 * @brief Constructor to create an action segment with just an array.
	 *
	 * The Offset will be set to 0, and the Length will be set to the length of the provided array.
	 *
	 * @param InArray A shared pointer to the array to use for this segment.
	 */
	FActionSegment(TSharedPtr<TArray<T>> InArray)
		: FActionSegment(InArray.IsValid() ? InArray : FActionSegment<T>::GetEmptyArray(), 0,
			  InArray.IsValid() ? InArray->Num() : 0)
	{
	}

	/**
	 * @brief Constructor to create an action segment with an array, offset, and length.
	 *
	 * This constructor allows more fine-grained control over which part of the array the segment represents.
	 *
	 * @param InArray The underlying array.
	 * @param InOffset The zero-based offset into the array.
	 * @param InLength The number of elements in the segment.
	 */
	FActionSegment(TSharedPtr<TArray<T>> InArray, int32 InOffset, int32 InLength)
		: Offset(InOffset), Length(InLength), Array(InArray.IsValid() ? InArray : GetEmptyArray())
	{
		CheckParameters(*Array, InOffset, InLength);
	}

	/**
	 * @brief Static function to return an empty array.
	 *
	 * This function provides a shared empty array that can be used when an action segment needs to represent no data.
	 *
	 * @return A shared pointer to an empty array.
	 */
	static TSharedPtr<TArray<T>> GetEmptyArray()
	{
		static TSharedPtr<TArray<T>> EmptyArray = MakeShared<TArray<T>>();
		return EmptyArray;
	}

	/**
	 * @brief Validates the provided parameters to ensure they are within the bounds of the array.
	 *
	 * This function checks that the specified offset and length are valid and within the bounds of the array.
	 *
	 * @param InArray The array to check against.
	 * @param InOffset The zero-based offset into the array.
	 * @param InLength The number of elements to access.
	 */
	static void CheckParameters(const TArray<T>& InArray, int32 InOffset, int32 InLength)
	{
		if (InOffset + InLength > InArray.Num())
		{
			UE_LOG(LogTemp, Error, TEXT("Arguments offset: %d and length: %d are out of bounds of array: %d."),
				InOffset, InLength, InArray.Num());
		}
	}

	/**
	 * @brief Overloads the array index operator for read access.
	 *
	 * Allows access to the segment elements via array syntax. Performs bounds checking.
	 *
	 * @param Index The zero-based index in the segment.
	 * @return The element at the specified index.
	 */
	T operator[](int32 Index) const
	{
		if (Index < 0 || Index >= Length)
		{
			UE_LOG(LogTemp, Error, TEXT("Index out of bounds, expected a number between 0 and %d"), Length - 1);
			return T(); // Return a default value or handle the error as needed.
		}
		return (*Array)[Offset + Index];
	}

	/**
	 * @brief Overloads the array index operator for write access.
	 *
	 * Allows modification of the segment elements via array syntax. Performs bounds checking.
	 *
	 * @param Index The zero-based index in the segment.
	 * @return A reference to the element at the specified index.
	 */
	T& operator[](int32 Index)
	{
		if (Index < 0 || Index >= Length)
		{
			UE_LOG(LogTemp, Error, TEXT("Index out of bounds, expected a number between 0 and %d"), Length - 1);
			static T DefaultValue = T(); // Return a default value reference or handle the error as needed.
			return DefaultValue;
		}
		return (*Array)[Offset + Index];
	}

	/**
	 * @brief Clears the segment, resetting all elements to their default values.
	 *
	 * This method clears the segment by setting all elements within the segment range to their default-initialized
	 * state.
	 */
	void Clear()
	{
		if (Array.IsValid())
		{
			TArray<T>& ArrayRef = *Array;

			if (Offset + Length <= ArrayRef.Num())
			{
				for (int32 i = Offset; i < Offset + Length; ++i)
				{
					ArrayRef[i] = T(); // Default-initialize each element.
				}
			}
		}
	}

	/**
	 * @brief Checks if the segment is empty.
	 *
	 * A segment is considered empty if its array is null or has a length of 0.
	 *
	 * @return True if the segment is empty, false otherwise.
	 */
	bool IsEmpty() const { return Array == nullptr || Array->Num() == 0; }

	/**
	 * @brief Equality operator.
	 *
	 * Compares two segments to determine if they are equal. Two segments are equal if they
	 * share the same offset, length, and underlying array.
	 *
	 * @param Other The other segment to compare to.
	 * @return True if the segments are equal, false otherwise.
	 */
	bool operator==(const FActionSegment& Other) const
	{
		return Offset == Other.Offset && Length == Other.Length && Array == Other.Array;
	}

	/**
	 * @brief Inequality operator.
	 *
	 * Compares two segments to determine if they are not equal.
	 *
	 * @param Other The other segment to compare to.
	 * @return True if the segments are not equal, false otherwise.
	 */
	bool operator!=(const FActionSegment& Other) const { return !(*this == Other); }
};
