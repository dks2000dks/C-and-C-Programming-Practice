#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
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
}

void BubbleSort(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		int o=0;

		for(int j=1;j<n;j++)
		{
			if(a[j-1] > a[j])
			{
				swap(a[j],a[j-1]);
				o++;
			}

			else
			{
				o--;			
			}
		}

		if (o + n == 0)
		{
			i = n;
		}
	}
}


int main()
{
	int n;
	cin >> n;

	int k[n] = {};
	Input_Array(k,n);

	BubbleSort(k,n);

	Print_Array(k,n);
	cout << endl;
}