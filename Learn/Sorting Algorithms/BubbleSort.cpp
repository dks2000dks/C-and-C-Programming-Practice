// Source Link: https://www.geeksforgeeks.org/bubble-sort/

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

void BubbleSort(int *a, int n){
	bool swap_performed;
	for(int i=0;i<n-1;i++){
		swap_performed = false;

		for(int j=0;j<n-i-1;j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				swap_performed = true;
			}
		}

		if (swap_performed == false){
			break;
		}
	}
}

int main(){
	int n;
	cin >> n;

	int k[n] = {};
	Input_Array(k,n);

	BubbleSort(k,n);
	Print_Array(k,n);
}