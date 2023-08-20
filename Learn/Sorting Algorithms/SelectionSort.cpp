// Source Link: https://www.geeksforgeeks.org/selection-sort/
// Additional: https://www.geeksforgeeks.org/difference-between-insertion-sort-and-selection-sort/

#include<bits/stdc++.h>
using namespace std;

void Input_Array(int *array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Print_Array(int *array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b){
	int s;
	s = a;
	a = b;
	b = s;
}

void SelectionSort(int *array, int size){
	int i, j, imin;
	
	for(i=0; i<size-1; i++){
		imin = i;
		for(j = i+1; j<size; j++){
        	if(array[j] < array[imin])
            	imin = j;
		}
		swap(array[i], array[imin]);
	}
}


int main (){
	int n;
	cin >> n;

	int a[n];
	Input_Array(a,n);

	SelectionSort(a,n);
	Print_Array(a,n);
}
