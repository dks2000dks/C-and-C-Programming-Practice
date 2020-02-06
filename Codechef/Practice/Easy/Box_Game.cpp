#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void Input_Array(long long int *array, long long int size)
{
	for (long long int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int Find_Index(long long int *array, long long int size,long long int find)
{
	long long int o;
	for (long long int i = 0;i < size; i++)
	{
		if (find == array[i])
		{
			o = i;
			i = size;
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
		long long int n,k,p,y;
		cin >> n >> k >> p;

		long long int a[n];
		Input_Array(a,n);

		long long int r=0;

		if (p==0)
		{
			long long int *il;
			il = max_element(a,a+n);
			y = *il;
			r = Find_Index(a,n,y);
		}

		else
		{
			long long int *il;
			il = min_element(a,a+n);
			y = *il;
			r = Find_Index(a,n,y);
		}

		for (int i=1;i<k;i++)
		{
			if (p==1)
				p=0;
			else
				p=1;
				
			if (p==0)
			{
				if (a[r-1] > a[r+1])
					r = r-1;
				
				else
					r = r+1;
			}

			else
			{
				if (a[r-1] > a[r+1])
					r = r+1;
				
				else
					r = r-1;
			}
		}

		cout << a[r] << endl;
	}
}
