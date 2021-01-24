#pragma once

#include <iostream>
#include <algorithm>

#define INDEX_OUT_OF_RANGE_MESSAGE "ERROR: INDEX IS OUT OF RSNGE"
#define NEGATIVE_SIZE_MESSAGE "ERROR: SIZE IS NEGATIVE"
#define ZERO_SIZE_MESSAGE "ERROR: EMPTY STRUCTURE"

template <typename T> class LinkedList 
{
private:
	struct List 
	{
		T item;
		List* next = nullptr;
	};

	List* head = nullptr;
	int size = 0;

public:

	LinkedList() : size(0) {}

	LinkedList(T* items, int size) : LinkedList() 
	{
		if (size < 0) 
			throw NEGATIVE_SIZE_MESSAGE;

		List** elem = &(this->head);
		for (int i = 0; i < size; i++) 
		{
			*elem = new List;
			(*elem)->item = items[i];
			elem = &((*elem)->next);
		}

		this->size = size;
	}


	LinkedList(int size) : LinkedList() 
	{
		if (size < 0) 
			throw NEGATIVE_SIZE_MESSAGE;

		List** elem = &(this->head);
		for (int i = 0; i < size; i++) 
		{
			*elem = new List;
			(*elem)->item = T();
			elem = &((*elem)->next);
		}

		this->size = size;
	}


	LinkedList(const LinkedList<T>& list) 
	{
		List* elem = list.head;
		List** newelem = &(this->head);

		for (int i = 0; i < list.size; i++, elem = elem->next) 
		{
			*newelem = new List;
			(*newelem)->item = elem->item;
			newelem = &((*newelem)->next);
		}

		this->size = list.size;
	}

	virtual ~LinkedList() 
	{
		List* elem = this->head;
		List* next;
		while (elem != nullptr) 
		{
			next = elem->next;
			delete elem;
			elem = next;
		}

		this->size = 0;
	}


	T GetFirst() const 
	{
		if (this->size == 0) 
			throw ZERO_SIZE_MESSAGE;
		
		return this->head->item;
	}

	T GetLast() const 
	{
		if (this->size == 0) 
			throw ZERO_SIZE_MESSAGE;
		List* elem = this->head;
		while (elem->next != nullptr) 
			elem = elem->next;
		return elem->item;
	}

	T Get(int index) const 
	{
		if (index < 0 || index >= this->size) 
			throw INDEX_OUT_OF_RANGE_MESSAGE;

		List* elem = this->head;
		for (int i = 0; i < index; i++)
			elem = elem->next;

		return elem->item;
	}

	void Set(const T& item, int index) 
	{
		if (index < 0 || index >= this->size) 
			throw INDEX_OUT_OF_RANGE_MESSAGE;

		List* elem=this->head;
		for (int i = 0; i < index; i++)
			elem = elem->next;
		elem->item = item;
	}

	LinkedList<T>* GetSubList(int start, int end) const 
	{
		if (start < 0 || start >= this->size || end < 0 || end > this->size) 
			throw INDEX_OUT_OF_RANGE_MESSAGE;

		LinkedList<T>* newList = new LinkedList<T>();

		List* elem = this->head;
		List** newelem = &newList->head;

		for (int i = 0; i < end; i++, elem = elem->next) 
			if (i >= start) 
			{
				*newelem = new List;
				(*newelem)->item = elem->item;
				newelem = &((*newelem)->next);
			}

		newList->size = end - start;

		return newList;
	}

	int GetSize() const 
	{ 
		return this->size; 
	}

	void Append(const T& item) 
	{
		List** elem = &(this->head);

		while (*elem != nullptr) 
			elem = &((*elem)->next);
		(*elem) = new List;
		(*elem)->item = item;

		this->size++;
	}

	void Prepend(const T& item) 
	{
		List* elem = new List{ item, this->head };
		this->head = elem;

		this->size++;
	}

	void InsertAt(const T& item, int index) 
	{
		if (index < 0 || index > this->size) 
			throw INDEX_OUT_OF_RANGE_MESSAGE;

		List prehead;
		prehead.next = this->head;
		List *elem=&prehead;

		for (int i = 0; i<index; i++)
			elem = elem->next;

		elem->next = new List{ item, elem->next };
		this->head = prehead.next;
	
		this->size++;
	}

	LinkedList<T>* Concat(const LinkedList<T>& list) const 
	{
		List* first = this->head;
		List* second = list.head;

		LinkedList<T>* newList = new LinkedList<T>();
		List** elem = &(newList->head);
		while (first != nullptr) 
		{
			*elem = new List;
			(*elem)->item = first->item;
			(*elem)->next = first->next;
			first = first->next;
			elem = &((*elem)->next);
		}
		while (second != nullptr) 
		{
			*elem = new List;
			(*elem)->item = second->item;
			(*elem)->next = second->next;
			second = second->next;
			elem = &((*elem)->next);
		}

		newList->size = this->size + list.size;
		return newList;
	}

	bool operator==(const LinkedList<T>& arr) const 
	{
		if (this->size != arr.size)
			return false;

		for (int i = 0; i < this->size; i++)
			if (this->Get(i) != arr.Get(i))
				return false;

		return true;
	}
};
