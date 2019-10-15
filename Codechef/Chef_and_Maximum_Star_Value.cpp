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

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n;
		cin >> n;
		int a[n];
		Input_Array(a,n);

		int o=0;

		for(int i=0;i<n;i++)
		{
			int c=0;

			for(int j=0;j<i;j++)
			{
				int l = a[j];
				int m = a[i];

				if(l%m == 0)
				{
					c++;
				}
			}

			o = max(o,c);
		}

		cout << o << endl;
	}
}