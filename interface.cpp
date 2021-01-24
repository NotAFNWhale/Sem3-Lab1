#pragma once

#include <iostream>
#include <iomanip>
#include "sorts.h"

using namespace std;


ArraySequence<int>* Input()
{
	int inpway;
	cout << "How will your array be created?" << endl;
	cout << "\t1.Manual" << endl;
	cout << "\t2.Random Generation" << endl;
	cin >> inpway;
	int size;
	cout << "Input size of array" << endl;
	cin >> size;
	while (size < 0)
	{
		cout << "Size of array must be >=0" << endl;
		cout << "Input size of array" << endl;
		cin >> size;
	}

	int k;
	ArraySequence<int>* arrofint = new ArraySequence<int>(size);

	switch (inpway)
	{
	case 1:
		cout << "Input " << size << " numbers: ";
		for (int i = 0; i < size; i++)
		{
			cin >> k;
			arrofint->Set(k, i);
		}
		break;
	case 2:
		cout << "Generated array is: ";
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			k = rand();
			arrofint->Set(k, i);
			cout << k << " ";
		}
		cout << endl;
		break;
	}
	return arrofint;
}

ArraySequence<int>* ArrayCopier(ArraySequence<int>* arrofint)
{
	ArraySequence<int>* copied = new ArraySequence<int>(arrofint->GetSize());
	for (int i = 0; i < arrofint->GetSize(); i++)
		copied->Set(arrofint->Get(i), i);
	return copied;
}

void SortChoise(int& sort_number)
{
	cout << "Choose Sort:" << endl;
	cout << "\t1. Quick" << endl;
	cout << "\t2. Merge" << endl;
	cout << "\t3. Selection" << endl;
	cout << "\t4. Bublle" << endl;
	cin >> sort_number;
}

void SortTimeCheck(int sort_number, ArraySequence<int>* arr)
{
	ArraySequence<int>* copied = ArrayCopier(arr);
	switch (sort_number)
	{
	case 1:
		cout << GetTimeSort(copied, QuickSort) << endl;
		break;
	case 2:
		cout << GetTimeSort(copied, MergeSort) << endl;
		break;
	case 3:
		cout << GetTimeSort(copied, SelectionSort) << endl;
		break;
	case 4:
		cout << GetTimeSort(copied, BubbleSort) << endl;
		break;
	}
	delete copied;
}

void TimeComporator(ArraySequence<int>* arr)
{
	SortTimeCheck(1, arr);
	SortTimeCheck(2, arr);
	SortTimeCheck(3, arr);
	SortTimeCheck(4, arr);
}

void interface()
{
	ArraySequence<int>* arrofint;
	arrofint = Input();
	int act = 0;
	int sort_number;
	while (act != 4)
	{
		cout << "Choose action with array:" << endl;
		cout << "\t1. Check one sort time" << endl;
		cout << "\t2. Compare sort times" << endl;
		cout << "\t3. Input new array" << endl;
		cout << "\t4. Exit" << endl;
		cout << "Action number:";
		cin >> act;
		switch (act)
		{
		case 1:
			SortChoise(sort_number);
			cout << "This sort time for your array is:";
			SortTimeCheck(sort_number, arrofint);
			break;
		case 2:
			TimeComporator(arrofint);
			break;
		case 3:
			arrofint=Input();
			break;
		case 4:
			break;
		default:
			cout << "WRONG ACTION NUMBER" << endl;
			break;
		}
	}
}