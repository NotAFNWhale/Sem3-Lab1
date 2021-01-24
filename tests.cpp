#include "sorts.h"
#include <iostream>
#include <cassert>
using namespace std;

void testDynamicArray() {
	int initArr1[] = { 1,2,3,4,5 };
	int initArr2[] = { 0,2,3,4,5,6 };
	int initArr3[] = { 0,2,3,4 };

	DynamicArray<int> arr1(initArr1, 5);
	assert(arr1 == DynamicArray<int>(arr1));
	assert(arr1 == DynamicArray<int>(arr1, 5));
	assert(DynamicArray<int>() == DynamicArray<int>((int*)0, 0));
	assert(arr1.Get(0) == 1);
	assert(arr1.Get(3) == 4);
	assert(arr1.Get(4) == 5);
	assert(arr1.GetSize() == 5);

	arr1.Resize(6);
	arr1.Set(0, 0);
	arr1.Set(6, 5);
	assert(arr1 == DynamicArray<int>(initArr2, 6));
	arr1.Resize(4);
	assert(arr1 == DynamicArray<int>(initArr3, 4));
}

void testLinkedList() {
	int initArr1[] = {1, 2, 3, 5};
	int initArr2[] = {-1, 0, 1, 2, 3, 4, 5, 6, 7};
	int initArr3[] = {-1};
	int initArr35[] = {-2, 0, 1, 2, 3, 4, 5, 0, 8};
	int initArr4[] = {0, 1, 2, 3, 5, 0};
	int initArr5[] = {-2, 0, 1, 2, 3, 4, 5, 0, 8, -1};
	int initArr6[] = { -2, 0, 1, 2, 3, 4, 5, 0, 8, 1, 2, 3, 5};

	LinkedList<int> list1(initArr1, 4);

	assert(list1 == LinkedList<int>(list1));
	assert(LinkedList<int>() == LinkedList<int>((int*)0, 0));
	assert(list1.Get(0) == 1);
	assert(list1.GetFirst() == 1);
	assert(list1.Get(2) == 3);
	assert(list1.Get(3) == 5);
	assert(list1.GetLast() == 5);
	assert(list1.GetSize() == 4);

	list1.Prepend(0);
	list1.Append(6);
	list1.InsertAt(-1, 0);
	list1.InsertAt(7, 7);
	list1.InsertAt(4, 5);
	assert(list1 == LinkedList<int>(initArr2, 9));

	LinkedList<int>* list2 = list1.GetSubList(0, 0);
	LinkedList<int>* list3 = list1.GetSubList(0, 1);
	LinkedList<int>* list4 = list1.GetSubList(0, 9);
	assert(*list2 == LinkedList<int>());
	assert(*list3 == LinkedList<int>(initArr3, 1));
	assert(*list4 == list1);

	list1.Set(-2, 0);
	list1.Set(8, 8);
	list1.Set(0, 7);
	assert(list1 == LinkedList<int>(initArr35, 9));

	LinkedList<int>* list5 = list1.Concat(LinkedList<int>());
	LinkedList<int>* list6 = list1.Concat(LinkedList<int>(initArr3, 1));
	LinkedList<int>* list7 = list1.Concat(LinkedList<int>(initArr1, 4));
	assert(*list5 == list1);
	assert(*list6 == LinkedList<int>(initArr5, 10));
	assert(*list7 == LinkedList<int>(initArr6, 13));

	delete list2;
	delete list3;
	delete list4;
	delete list5;
	delete list6;
	delete list7;
}

void testArraySequence() {
	int initArr1[] = { 1,2,3,5 };
	int initArr2[] = { -1,0,1,2,3,4,5,6,7 };
	int initArr3[] = { -1 };
	int initArr35[] = { -2,0,1,2,3,4,5,0,8 };
	int initArr4[] = { 0,1,2,3,5,6 };
	int initArr5[] = { -2,0,1,2,3,4,5,0,8,-1 };
	int initArr6[] = { -2,0,1,2,3,4,5,0,8,1,2,3,5 };

	ArraySequence<int> seq1(initArr1, 4);

	assert(seq1 == ArraySequence<int>(seq1));
	assert(ArraySequence<int>() == ArraySequence<int>((int*)0, 0));
	assert(seq1.Get(0) == 1);
	assert(seq1.GetFirst() == 1);
	assert(seq1.Get(2) == 3);
	assert(seq1.Get(3) == 5);
	assert(seq1.GetLast() == 5);
	assert(seq1.GetSize() == 4);

	seq1.Prepend(0);
	seq1.Append(6);
	seq1.InsertAt(-1, 0);
	seq1.InsertAt(7, 7);
	seq1.InsertAt(4, 5);
	assert(seq1 == ArraySequence<int>(initArr2, 9));

	ArraySequence<int>* seq2 = seq1.GetSubSequence(0, 0);
	ArraySequence<int>* seq3 = seq1.GetSubSequence(0, 1);
	ArraySequence<int>* seq4 = seq1.GetSubSequence(0, 9);
	assert(*seq2 == ArraySequence<int>());
	assert(*seq3 == ArraySequence<int>(initArr3, 1));
	assert(*seq4 == seq1);

	seq1.Set(-2, 0);
	seq1.Set(8, 8);
	seq1.Set(0, 7);
	assert(seq1 == ArraySequence<int>(initArr35, 9));

	ArraySequence<int>* seq5 = seq1.Concat(ArraySequence<int>());
	ArraySequence<int>* seq6 = seq1.Concat(ArraySequence<int>(initArr3, 1));
	ArraySequence<int>* seq7 = seq1.Concat(ArraySequence<int>(initArr1, 4));
	assert(*seq5 == seq1);
	assert(*seq6 == ArraySequence<int>(initArr5, 10));
	assert(*seq7 == ArraySequence<int>(initArr6, 13));

	//delete seq2;
	delete seq3;
	delete seq4;
	delete seq5;
	delete seq6;
	delete seq7;
}

void testListSequence() {
	int initArr1[] = { 1,2,3,5 };
	int initArr2[] = { -1,0,1,2,3,4,5,6,7 };
	int initArr3[] = { -1 };
	int initArr35[] = { -2,0,1,2,3,4,5,0,8 };
	int initArr4[] = { 0,1,2,3,5,6 };
	int initArr5[] = { -2,0,1,2,3,4,5,0,8,-1 };
	int initArr6[] = { -2,0,1,2,3,4,5,0,8,1,2,3,5 };

	ListSequence<int> seq1(initArr1, 4);

	assert(seq1 == ListSequence<int>(seq1));
	assert(ListSequence<int>() == ListSequence<int>((int*)0, 0));
	assert(seq1.Get(0) == 1);
	assert(seq1.GetFirst() == 1);
	assert(seq1.Get(2) == 3);
	assert(seq1.Get(3) == 5);
	assert(seq1.GetLast() == 5);
	assert(seq1.GetSize() == 4);

	seq1.Prepend(0);
	seq1.Append(6);
	seq1.InsertAt(-1, 0);
	seq1.InsertAt(7, 7);
	seq1.InsertAt(4, 5);
	assert(seq1 == ListSequence<int>(initArr2, 9));

	ListSequence<int>* seq2 = seq1.GetSubSequence(0, 0);
	ListSequence<int>* seq3 = seq1.GetSubSequence(0, 1);
	ListSequence<int>* seq4 = seq1.GetSubSequence(0, 9);
	assert(*seq2 == ListSequence<int>());
	assert(*seq3 == ListSequence<int>(initArr3, 1));
	assert(*seq4 == seq1);

	seq1.Set(-2, 0);
	seq1.Set(8, 8);
	seq1.Set(0, 7);
	assert(seq1 == ListSequence<int>(initArr35, 9));

	ListSequence<int>* seq5 = seq1.Concat(ListSequence<int>());
	ListSequence<int>* seq6 = seq1.Concat(ListSequence<int>(initArr3, 1));
	ListSequence<int>* seq7 = seq1.Concat(ListSequence<int>(initArr1, 4));
	assert(*seq5 == seq1);
	assert(*seq6 == ListSequence<int>(initArr5, 10));
	assert(*seq7 == ListSequence<int>(initArr6, 13));

	delete seq2;
	delete seq3;
	delete seq4;
	delete seq5;
	delete seq6;
	delete seq7;

}

void testSortFunctions()
{
	ArraySequence<int>* arr0 = new ArraySequence<int>(0);

	BubbleSort(arr0);
	assert(arr0->GetSize() == 0);
	MergeSort(arr0);
	assert(arr0->GetSize() == 0);
	QuickSort(arr0);
	assert(arr0->GetSize() == 0);
	delete arr0;


	ArraySequence<int>* arr1 = new ArraySequence<int>(1);
	arr1->Set(3, 0);

	BubbleSort(arr1);
	assert(arr1->GetSize() == 1);
	assert(arr1->GetFirst() == 3);
	MergeSort(arr1);
	assert(arr1->GetSize() == 1);
	assert(arr1->GetFirst() == 3);
	QuickSort(arr1);
	assert(arr1->GetSize() == 1);
	assert(arr1->GetFirst() == 3);
	delete arr1;


	ArraySequence<int>* arr2 = new ArraySequence<int>(5);
	arr2->Set(6, 0);
	arr2->Set(3, 1);
	arr2->Set(5, 2);
	arr2->Set(7, 3);
	arr2->Set(4, 4);

	BubbleSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 3);
	assert(arr2->Get(1) == 4);
	assert(arr2->Get(2) == 5);
	assert(arr2->Get(3) == 6);
	assert(arr2->Get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->Set(1, 0);
	arr2->Set(1, 1);
	arr2->Set(1, 2);
	arr2->Set(1, 3);
	arr2->Set(1, 4);
	BubbleSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 1);
	assert(arr2->Get(1) == 1);
	assert(arr2->Get(2) == 1);
	assert(arr2->Get(3) == 1);
	assert(arr2->Get(4) == 1);
	delete arr2;


	arr2 = new ArraySequence<int>(5);
	arr2->Set(6, 0);
	arr2->Set(3, 1);
	arr2->Set(5, 2);
	arr2->Set(7, 3);
	arr2->Set(4, 4);
	MergeSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 3);
	assert(arr2->Get(1) == 4);
	assert(arr2->Get(2) == 5);
	assert(arr2->Get(3) == 6);
	assert(arr2->Get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->Set(1, 0);
	arr2->Set(1, 1);
	arr2->Set(1, 2);
	arr2->Set(1, 3);
	arr2->Set(1, 4);
	MergeSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 1);
	assert(arr2->Get(1) == 1);
	assert(arr2->Get(2) == 1);
	assert(arr2->Get(3) == 1);
	assert(arr2->Get(4) == 1);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->Set(6, 0);
	arr2->Set(3, 1);
	arr2->Set(5, 2);
	arr2->Set(7, 3);
	arr2->Set(4, 4);
	QuickSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 3);
	assert(arr2->Get(1) == 4);
	assert(arr2->Get(2) == 5);
	assert(arr2->Get(3) == 6);
	assert(arr2->Get(4) == 7);
	delete arr2;

	arr2 = new ArraySequence<int>(5);
	arr2->Set(1, 0);
	arr2->Set(1, 1);
	arr2->Set(1, 2);
	arr2->Set(1, 3);
	arr2->Set(1, 4);
	QuickSort(arr2);
	assert(arr2->GetSize() == 5);
	assert(arr2->Get(0) == 1);
	assert(arr2->Get(1) == 1);
	assert(arr2->Get(2) == 1);
	assert(arr2->Get(3) == 1);
	assert(arr2->Get(4) == 1);
	delete arr2;
}



int main() {
	testDynamicArray();
	cout << "Dynamic Array passed tests" << endl;
	testLinkedList();
	cout << "Linked List passed tests" << endl;
	testArraySequence();
	cout << "Array Sequenece passed tests" << endl;
	testListSequence();
	cout << "List Sequence passed tests" << endl;
	testSortFunctions();
	cout << "Sort functions passed tests" << endl;
	return 0;
}