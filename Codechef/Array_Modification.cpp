#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void Input_Array(long long int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

void Print_Array(long long int *array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
}

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		long long n,k;
		cin >> n >> k;

		long long int a[n];

		Input_Array(a,n);

		int y = k % (3*n);

		if(y==0)
			y = 3*n;

		for(int i=0;i<y;i++)
		{
			int t = i%n;
			int p = a[t];
			int q = a[n-1-t];

			a[t] = p^q;
		}

		if (n%2 == 1 && k>n/2)
		{
			a[n/2] = 0;
		}	

		Print_Array(a,n);
		cout << endl;
	}
}