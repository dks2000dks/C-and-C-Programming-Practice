// Source Link: https://courses.csail.mit.edu/6.006/fall10/handouts/recitation10-8.pdf

#include<bits/stdc++.h>
using namespace std;

void Input_Array(int *v, int size){
	// Take "n" elements as input for an array "v".
	for (int i = 0; i < size; i++){
		cin >> v[i];
	}
}

void Print_Array(int *v, int size){
	// Print "n" elements of an array "v".
	for (int i = 0; i < size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void MaxHeapify(int *array, int n, int i){
	/*
	Max-Heapify
		*array: Array of elements.
		n: Size of heap.
		i: Index in heap.
	*/

	int l = 2*i + 1;
	int r = 2*i + 2;

	int largest = i;

	if (l<n && array[l] > array[i])
		largest = l;

	if (r<n && array[r]  > array[largest])
		largest = r;

	if (largest != i){
		swap(array[i],array[largest]);
		MaxHeapify(array,n,largest);
	}
}

void BuildMaxHeap(int *array, int n){
	/*
	Building Max-Heap
		*array: Array of elements.
		n: Size of heap.
	*/

	int heapsize = n;

	for (int i=(n/2)-1; i>=0; i--){
		MaxHeapify(array,heapsize,i);
	}
}

void HeapSort(int *array, int n){
	/*
	Heap Sort
		*array: Array of elements.
		n: Size of heap.
	*/

	BuildMaxHeap(array,n);

	int heapsize = n;
	for (int i=n-1; i>=0; i--){
		swap(array[0],array[i]);
		heapsize -= 1;
		MaxHeapify(array,heapsize,0);
	}
}

int main(){
	int n;
	cin >> n;

	// MaxHeap prints array in increasing order.
	// Max Elements are inserted at the Last of the Array.
	int Data[n];

	Input_Array(Data,n);
	HeapSort(Data,n);
	Print_Array(Data,n);
}