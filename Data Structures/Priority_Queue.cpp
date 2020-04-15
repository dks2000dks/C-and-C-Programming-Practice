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

int HeapMaximum(int *array)
{
	return array[0];
}

int HeapExtractMax(int *array, int heapsize)
{
	if (heapsize < 1)
		cout << "Error: Heap Overflow" << endl;
	int max = array[0];
	array[0] = array[heapsize-1];
	heapsize = heapsize-1;
	MaxHeapify(array,heapsize,1);
	return max;
}

void HeapIncreaseKey(int *array, int index, int key)
{
	if (key < array[index])
		cout << "Error: New Element is smaller than Key" << endl;
	array[index] = key;
	int ParentIndex = floor((index-1)/2);
	while (index>1 && array[ParentIndex] < array[index])
	{
		swap(array[index],array[ParentIndex]);
		index = ParentIndex;
	}
}

void MaxHeapInsert(int *array,int heapsize, int key)
{
	heapsize++;
	array[heapsize-1] = INT_MIN;
	HeapIncreaseKey(array,heapsize-1,key);
}

int main()
{
	int n,e;
	cin >> n;

	int Data[n];

	Input_Array(Data,n);
	cout << "---------" << endl;
	HeapSort(Data,n);
	Print_Array(Data,n);

	// MaxHeap prints array in increasing order.
	// Max Elements are inserted at the Last of the Array.

	// Reordering Data in decreasing order.
	int DataR[n];
	for(int i=0;i<n;i++)
	{
		DataR[i] = Data[n-1-i];
	}

	int Max = HeapExtractMax(DataR,n);
	Print_Array(DataR,n-1);
	
	cout << "Insert a Node in Heap : ";
	cin >> e;
	MaxHeapInsert(DataR,n-1,e);
	n = sizeof(DataR)/sizeof(*DataR);
	Print_Array(DataR,n);

	HeapIncreaseKey(DataR,6,15);
	Print_Array(DataR,n);

	HeapSort(DataR,n,1);
	Print_Array(DataR,n);
}