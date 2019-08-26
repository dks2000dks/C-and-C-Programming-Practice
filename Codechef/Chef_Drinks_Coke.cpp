#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void Input_Two_Array(int *array, int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
		cin >> arr[i];
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


int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		int n,m,k,l,r;
		
		cin >> n >> m >> k >> l >> r;

		int C[n];
		int P[n];

		Input_Two_Array(C,P,n);

    	int min = INT_MAX;
    	int p = 0;

		for (int i=0;i<n;i++)
		{
			int t;
			t = C[i];

			for (int j=0;j<m;j++)
			{
				if (t > k+1)
				{
					t = t-1;
				}
				elseif (t < k-1)
				{
					t = t+1;
				}
				elseif (t < k+2 && t > k-2)
				{
					t = k;
				}
			}

			if (t > l-1 && t < r+1)
			{
				p = 1;
				if (min > P[i])
				{
					min = P[i];
				}
			}
		}

		if (p == 1)
		{
			cout << min << endl;
		}

		else
		{
			cout << -1 << endl;
		}
	}
}