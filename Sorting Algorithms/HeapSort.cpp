#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

void Input_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

void Print_Array(int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void MaxHeapify(int *array, int n, int i)
{
	// n --- Heap Size
	// i --- Heap Index

	int l = 2*i + 1;
	int r = 2*i + 2;

	int largest = i;

	if (l<n && array[l] > array[i])
		largest = l;

	if (r<n && array[r]  > array[largest])
		largest = r;

	if (largest != i)
	{
		swap(array[i],array[largest]);
		MaxHeapify(array,n,largest);
	}
}

void BuildMaxHeap(int *array, int n)
{
	// n = Size of Input

	int heapsize = n;

	for (int i=(n/2); i>=0; i--)
	{
		MaxHeapify(array,heapsize,i);
	}
}

void HeapSort(int *array, int n)
{
	// n -- Size of Input

	BuildMaxHeap(array,n);

	int heapsize = n;

	for (int i=n-1; i>=0; i--)
	{
		swap(array[0],array[i]);
		heapsize -= 1;
		MaxHeapify(array,heapsize,0);
	}
}

int main()
{
	int n;
	cin >> n;

	// MaxHeap prints array in increasing order.
	// Max Elements are inserted at the Last of the Array.
	int Data[n];

	Input_Array(Data,n);
	HeapSort(Data,n);
	Print_Array(Data,n);
}