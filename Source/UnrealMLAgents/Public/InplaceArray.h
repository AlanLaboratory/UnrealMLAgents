#pragma once

#include "CoreMinimal.h"

/**
 * @struct FInplaceArray
 * @brief A simple array-like structure that can store up to four elements.
 *
 * The `FInplaceArray` struct is a fixed-size array that can store up to four elements of a specified type.
 * It does not allocate any additional memory beyond the fixed number of elements, making it suitable for cases
 * where memory efficiency is important, and the array size is small.
 *
 * @tparam T The type of the elements stored in the array.
 */
template <typename T> struct FInplaceArray
{
private:
	/** The maximum length of the array. */
	static const int32 MaxLength = 4;

	/** The current length of the array (i.e., how many elements are used). */
	int32 Length;

	/** The first element of the array. */
	T Elem0;

	/** The second element of the array. */
	T Elem1;

	/** The third element of the array. */
	T Elem2;

	/** The fourth element of the array. */
	T Elem3;

public:
	/**
	 * @brief Default constructor that initializes an empty array.
	 *
	 * The length is set to zero, and all elements are initialized to their default values.
	 */
	FInplaceArray() : Length(0), Elem0(T()), Elem1(T()), Elem2(T()), Elem3(T()) {}

	/**
	 * @brief Constructor that initializes the array with one element.
	 *
	 * The first element is set to the provided value, and the remaining elements are initialized to their default
	 * values.
	 *
	 * @param InElem0 The first element to store in the array.
	 */
	FInplaceArray(T InElem0) : Length(1), Elem0(InElem0), Elem1(T()), Elem2(T()), Elem3(T()) {}

	/**
	 * @brief Constructor that initializes the array with two elements.
	 *
	 * The first two elements are set to the provided values, and the remaining elements are initialized to their
	 * default values.
	 *
	 * @param InElem0 The first element to store in the array.
	 * @param InElem1 The second element to store in the array.
	 */
	FInplaceArray(T InElem0, T InElem1) : Length(2), Elem0(InElem0), Elem1(InElem1), Elem2(T()), Elem3(T()) {}

	/**
	 * @brief Constructor that initializes the array with three elements.
	 *
	 * The first three elements are set to the provided values, and the remaining element is initialized to its default
	 * value.
	 *
	 * @param InElem0 The first element to store in the array.
	 * @param InElem1 The second element to store in the array.
	 * @param InElem2 The third element to store in the array.
	 */
	FInplaceArray(T InElem0, T InElem1, T InElem2)
		: Length(3), Elem0(InElem0), Elem1(InElem1), Elem2(InElem2), Elem3(T())
	{
	}

	/**
	 * @brief Constructor that initializes the array with four elements.
	 *
	 * All elements are set to the provided values.
	 *
	 * @param InElem0 The first element to store in the array.
	 * @param InElem1 The second element to store in the array.
	 * @param InElem2 The third element to store in the array.
	 * @param InElem3 The fourth element to store in the array.
	 */
	FInplaceArray(T InElem0, T InElem1, T InElem2, T InElem3)
		: Length(4), Elem0(InElem0), Elem1(InElem1), Elem2(InElem2), Elem3(InElem3)
	{
	}

	/**
	 * @brief Gets the current length of the array (i.e., how many elements are in use).
	 *
	 * @return The number of elements in the array.
	 */
	int32 GetLength() const { return Length; }

	/**
	 * @brief Accesses an element by index.
	 *
	 * This operator provides access to the elements in the array using an index.
	 * The index must be between 0 and the current length of the array.
	 *
	 * @param Index The index of the element to access.
	 * @return A reference to the element at the specified index.
	 */
	T& operator[](int32 Index)
	{
		check(Index >= 0 && Index < Length);
		switch (Index)
		{
			case 0:
				return Elem0;
			case 1:
				return Elem1;
			case 2:
				return Elem2;
			case 3:
				return Elem3;
			default:
				checkNoEntry();
				return Elem0; // To satisfy the compiler.
		}
	}

	/**
	 * @brief Accesses an element by index (const version).
	 *
	 * This operator provides const access to the elements in the array using an index.
	 *
	 * @param Index The index of the element to access.
	 * @return A constant reference to the element at the specified index.
	 */
	const T& operator[](int32 Index) const
	{
		check(Index >= 0 && Index < Length);
		switch (Index)
		{
			case 0:
				return Elem0;
			case 1:
				return Elem1;
			case 2:
				return Elem2;
			case 3:
				return Elem3;
			default:
				checkNoEntry();
				return Elem0; // To satisfy the compiler.
		}
	}

	/**
	 * @brief Creates an FInplaceArray from a TArray.
	 *
	 * The source array must have between 1 and 4 elements.
	 * If the source array has more than 4 elements, an error is logged.
	 *
	 * @param Elems The source array.
	 * @return An FInplaceArray with the first 1-4 elements from the source array.
	 */
	static FInplaceArray<T> FromArray(const TArray<T>& Elems)
	{
		switch (Elems.Num())
		{
			case 1:
				return FInplaceArray<T>(Elems[0]);
			case 2:
				return FInplaceArray<T>(Elems[0], Elems[1]);
			case 3:
				return FInplaceArray<T>(Elems[0], Elems[1], Elems[2]);
			case 4:
				return FInplaceArray<T>(Elems[0], Elems[1], Elems[2], Elems[3]);
			default:
				UE_LOG(LogTemp, Error, TEXT("Array must have between 1 and 4 elements"));
				return FInplaceArray<T>();
		}
	}
};
