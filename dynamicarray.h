#pragma once

#include <iostream>
#include <algorithm>

#define INDEX_OUT_OF_RANGE_MESSAGE "ERROR: INDEX IS OUT OF RSNGE"
#define NEGATIVE_SIZE_MESSAGE "ERROR: SIZE IS NEGATIVE"
#define ZERO_SIZE_MESSAGE "ERROR: EMPTY STRUCTURE"

template <typename T> class DynamicArray
{
private:
	T* item = nullptr;
	int size = 0;
public:
	DynamicArray() : size(0) {}

	DynamicArray(int size) : size(size)	
	{
		if (size < 0)
			throw NEGATIVE_SIZE_MESSAGE;
		this->item = new T[size];
	}


	DynamicArray(T* items, int size) : DynamicArray(size)
	{
		for (int i = 0; i < size; i++)
			this->item[i] = items[i];
	}

	DynamicArray(const DynamicArray<T>& arr, int size) : DynamicArray(size)
	{
		if (size > arr.size)
			throw INDEX_OUT_OF_RANGE_MESSAGE;

		for (int i = 0; i < size; i++)
			this->item[i] = arr.item[i];
	}

	DynamicArray(const DynamicArray<T>& arr):DynamicArray(arr.item, arr.size) {}

	virtual ~DynamicArray()
	{
		delete[] this->item;
		this->size = 0;
	}


	T Get(int index) const
	{
		if (index < 0 || index >= this->size)
			throw INDEX_OUT_OF_RANGE_MESSAGE;
		return this->item[index];
	}

	int GetSize() const
	{
		return this->size;
	}

	void Set(const T& item, int index)
	{
		if (index < 0 || index >= this->size)
			throw INDEX_OUT_OF_RANGE_MESSAGE;
		this->item[index] = item;
	}

	void Resize(int size)
	{
		if (size < 0)
			throw NEGATIVE_SIZE_MESSAGE;

		T* newArr = new T[size];
		int max;
		if (size > this->size)
			max = size;
		else
			max = this->size;

		for (int i = 0; i < max; i++)
			newArr[i] = item[i];

		delete[] item;
		this->item = newArr;

		this->size = size;
	}

	bool operator==(const DynamicArray<T>& arr) const {
		if (this->size != arr.size) 
			return false;

		for (int i = 0; i < this->size; i++)
			if (this->Get(i) != arr.Get(i)) 
				return false;

		return true;
	}


};
