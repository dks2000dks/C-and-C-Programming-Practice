#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
	int s;
	s = a;
	a = b;
	b = s;
}


void Print_Array(int *array, int size)
{
	for (int i = 0;i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void SelectionSort(int *array, int size)
{

	int i, j, imin;
	
	for(i = 0; i<size-1; i++)
	{
		imin = i;

		for(j = i+1; j<size; j++)
        {
        	if(array[j] < array[imin])
            	imin = j;
		}
		swap(array[i], array[imin]);
	}
}


int main ()
{
	int n;
	cin >> n;
	int a[n];
	
	for (int i=0;i < n; i++)
	{
		cin >> a[i];
	}

	SelectionSort(a,n);
	Print_Array(a,n);
}
