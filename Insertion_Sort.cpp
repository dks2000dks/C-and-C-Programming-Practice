#include<iostream>
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
	for (int i = 0;i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void Insertion_Sort(int *array, int size)
{
	int i, j, min;
	
	for(i = 1; i<size; i++)
	{
		min = array[i];
		j = i-1;

		while(j>=0 && array[j] > min)
        {
        	array[j+1] = array[j];
        	j = j-1;
		}
		array[j+1] = min;
	}
}


int main ()
{
	int n;
	cin >> n;
	int a[n];
	
	Input_Array(a,n);
	Insertion_Sort(a,n);
	Print_Array(a,n);
}