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

int Count_Find(string str,char find)
{
	int size = str.length();
	int o = 0;
	for (int i = 0;i < size; i++)
	{
		if (find == str[i])
		{
			o++;
		}
	}

	return o;
}

void Multiply_Element_Array(int *array, int size, int m)
{
	for (int i = 0; i < size; i++)
	{
		array[i] =  m*array[i];
	}
}

void Input_Two_Array(int *array, int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
		cin >> arr[i];
	}
}

int Sum_elements_Array(int *array, int size)
{
	int o = 0;
	for (int i = 0; i < size; i++)
	{
		o += array[i];
	}

	return o;
}

int factorial(int t)
{
	int e = 1,p = 1,o = 0,f;

	while(e)
	{
		p = p * 5;
		f = t/p;
		o = o + t/p;

		if (f == 0)
		{
			e = 0;
		}
	
	}
	
	return o;
}

int Print_Primes(int a,int b)
{
	for (int n = a; n < b + 1;n++)
	{
		if (!(n%2 == 0 && n != 2))
		{
			int p = 1;
			for(int f = 3;f < sqrt(n) + 1;f = f+2)
			{
				if(n%f == 0)
				{
				p = 0;
				break;
				}
			}

			if (p == 1)
				cout << n << endl;
		}
	}
}

void swapping_elements_array(int &a, int &b)
{ 
	int x;
	x = a;
	a = b;
	b = x;
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

int Find_Index(int *array, int size,int find)
{
	int o;
	for (int i = 0;i < size; i++)
	{
		if (find == array[i])
		{
			o = i;
			i = size;
		}
	}

	return o;
}

int Fibonacci(int N)
{
	int o[N];

	o[0] = 0;
	o[1] = 1;

	for(int i=2;i<N;i++)
	{
		o[i] = o[i-1] + o[i-2];
	}

	return o;
}

int IsPrime(int n) 
{
	int o=1;

	if (n%2 == 0 && n!= 2) 
		o = 0;
  
	for (int i = 3; i < sqrt(n) + 1; i = i+2) 
		if (n % i == 0) 
			o = 0; 
  
    return o; 
}
