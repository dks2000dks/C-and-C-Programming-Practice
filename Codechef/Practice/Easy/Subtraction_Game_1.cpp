#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (b%a==0)
		return a;
	else
		return gcd(b,a%b);
}

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

		int input[n];
		int o;
		Input_Array(input,n);

		sort(input, input+n, greater<int>());

		for (int i=1;i<n;i++)
		{
			if (i==1)
			{
				o = gcd(input[i-1],input[i]);
			}

			else
			{
				o = gcd(o,input[i]);
			}

		}

		cout << o << endl;
	}
}