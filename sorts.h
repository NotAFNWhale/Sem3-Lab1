#pragma once

#include "sequence.h"
#include <chrono>

using namespace std;


template <class T>
double GetTimeSort(Sequence<T>* seq, void (*algSort)(Sequence<T>* seq))
{
    auto begin = chrono::steady_clock::now();
    algSort(seq);
    auto end = chrono::steady_clock::now();
    auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    return msec.count();
}


template <class T>
void merge(Sequence<T>* seq, int l, int r)
{
    int mid = (l + r) / 2;
    ArraySequence<T>* temp = new ArraySequence<T>(r - l + 1);
    int pos1 = l;
    int pos2 = mid + 1;
    int pos3 = 0;
    while (pos1 <= mid && pos2 <= r)
    {
        if (seq->Get(pos1) < seq->Get(pos2))
            temp->Set(seq->Get(pos1++), pos3++);
        else
            temp->Set(seq->Get(pos2++), pos3++);
    }
    while (pos2 <= r)
        temp->Set(seq->Get(pos2++), pos3++);
    
    while (pos1 <= mid)
        temp->Set(seq->Get(pos1++), pos3++);
    
    for (pos3 = 0; pos3 < r - l + 1; pos3++)
        seq->Set(temp->Get(pos3), l + pos3);
    delete temp;
}

template <class T>
void mergeSort(Sequence<T>* seq, int l, int r)
{
    if (l < r)
    {
        int mid = (r + l) / 2;
        mergeSort(seq, l, mid);
        mergeSort(seq, mid + 1, r);
        merge(seq, l, r);
    }
}

template <class T>
void quickSort(Sequence<T>* seq, int l, int r)
{
    int pivot = seq->Get(l);
    int lb = l;
    int rb = r;
    while (l < r)
    {
        while ((l < r) && (pivot < seq->Get(r)))
        {
            r--;
        }
        if (l != r)
        {
            seq->Set(seq->Get(r), l);
            l++;
        }
        while ((seq->Get(l) < pivot) && (l < r))
        {
            l++;
        }
        if (l != r)
        {
            seq->Set(seq->Get(l), r);
            r--;
        }
    }
    seq->Set(pivot, l);
    pivot = l;
    l = lb;
    r = rb;
    if (l < pivot)
        quickSort(seq, l, pivot - 1);
    if (r > pivot)
        quickSort(seq, pivot + 1, r);
}

template <class T>
void QuickSort(Sequence<T>* seq)
{
    if (seq->GetSize() <= 1)
        return;
    quickSort(seq, 0, seq->GetSize() - 1);
}


template <class T>
void MergeSort(Sequence<T>* seq)
{
    if (seq->GetSize() <= 1) return;
    mergeSort(seq, 0, seq->GetSize() - 1);
}

template <class T>
void SelectionSort(Sequence<T>* seq)
{
    if (seq->GetSize() <= 1)
        return;
    T swp = 0;
    for (int i = 0; i < seq->GetSize()-1; i++)
    {
        int minIndex =i;
        for (int j = i; j < seq->GetSize(); j++)
            if (seq->Get(j) < seq->Get(minIndex))
                minIndex = j;
        swp = seq->Get(minIndex);
        seq->Set(seq->Get(i), minIndex);
        seq->Set(swp, i);
    }
}

template <class T>
void BubbleSort(Sequence<T>* seq)
{
    if (seq->GetSize() <= 1) return;
    int size = seq->GetSize();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (seq->Get(i) < seq->Get(j))
            {
                T tmp = seq->Get(i);
                seq->Set(seq->Get(j), i);
                seq->Set(tmp, j);
            }
        }
    }
}