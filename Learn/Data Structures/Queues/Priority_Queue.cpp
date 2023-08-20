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

int HeapMaximum(int *array){
	// Return Max element of heap
	return array[0];
}

int HeapExtractMax(int *array, int heapsize){
	// Removing and Returning Max Element of Heap.
	if (heapsize < 1)
		cout << "Error: Heap Overflow" << endl;
	int max = array[0];
	array[0] = array[heapsize-1];
	heapsize = heapsize-1;
	MaxHeapify(array,heapsize,0);
	return max;
}

void HeapIncreaseKey(int *array, int index, int key){
	// Increasing value of key at an index
	if (key < array[index])
		cout << "Error: New Element is smaller than Key" << endl;
	array[index] = key;
	int ParentIndex = floor((index-1)/2);
	
	while (index>0 && array[ParentIndex] < array[index]){
		swap(array[index],array[ParentIndex]);
		index = ParentIndex;
		ParentIndex = floor((index-1)/2);
	}
}

void MaxHeapInsert(int *array,int heapsize, int key){
	// Adding a new element of heap
	heapsize++;
	array[heapsize-1] = INT_MIN;
	HeapIncreaseKey(array,heapsize-1,key);
}

int main(){
	int n,e;
	cin >> n;

	int Data[n];
	Input_Array(Data,n);

	cout << "---------" << endl;
	BuildMaxHeap(Data, n);
	Print_Array(Data,n);

	cout << "Extracting Max : " << endl;
	int Max = HeapExtractMax(Data,n);
	Print_Array(Data,n-1);
	
	cout << "Insert a Node in Heap : " << endl;
	cin >> e;
	MaxHeapInsert(Data,n-1,e);
	n = sizeof(Data)/sizeof(*Data);
	Print_Array(Data,n);

	cout << "Increasing key at index 1 to 15 : " << endl;
	HeapIncreaseKey(Data,1,15);
	Print_Array(Data,n);

	cout << "Heap Sort : " << endl;
	HeapSort(Data,n);
	Print_Array(Data,n);
}