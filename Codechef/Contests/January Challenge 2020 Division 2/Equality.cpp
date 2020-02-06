#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
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

int Compute(int *input, int n, int l, int r, int *data)
{
	int increase=0,decrease=0;
	// l = l-1;
	// r = r-1;
	int v=0;

	for(int i=l;i<r;i++)
	{
		if ((input[i-1] > input[i]) || v==1 || i==l)
		{
			if (input[i] < input[i+1])
			{
				if ((input[i+1] > input[i+2]) || i+1 == r)
				{
					// cout << "Increase: " << input[i] << " , " << input[i+1] << endl;
					increase++;
					v=0;
				}

				else
					v=1;
			}
		}
	}

	// cout << "No.of Increases: " << increase << endl;

	v=0;

	for(int i=l;i<r;i++)
	{
		if ((input[i-1] < input[i]) || v==1 || i==l)
		{
			if (input[i] > input[i+1])
			{
				if ((input[i+1] < input[i+2]) || i+1==r)
				{
					// cout << "Decrease: " << input[i] << " , " << input[i+1] << endl;
					decrease++;
					v=0;
				}
				
				else
					v = 1;
			}
		}
	}

	data[0] = increase;
	data[1] = decrease;

	// cout << "No. of Decreases: " << decrease << endl;
}

int Alternate(int *input, int *increase, int *decrease, int n)
{
	int inc=0,dec=0,a=0,b=0,x;
	for (int i=0;i<n-1;i++)
	{
		if (input[i] < input[i+1])
		{
			if (inc == 0)
			{
				x = increase[i];
				increase[i+1] = x+1;
				decrease[i+1] = decrease[i];
				inc = 1;
				dec = 0;
			}

			else
			{
				x = increase[i];
				increase[i+1] = x;
				decrease[i+1] = decrease[i];
				inc = 1;
				dec = 0;
			}
		}

		else
		{
			if (dec == 0)
			{
				x = decrease[i];
				decrease[i+1] = x+1;
				increase[i+1] = increase[i];
				dec = 1;
				inc = 0;
			}

			else
			{
				x = decrease[i];
				decrease[i+1] = x;
				increase[i+1] = increase[i];
				dec = 1;
				inc = 0;
			}
		}
	}
}

int main()
{
	int n,q;
	cin >> n >> q;
	int input[n];

	Input_Array(input,n);

	int increase[n] = {};
	int decrease[n] = {};
	int data[2];

	int l = 0,r;

	/*
	for (int r=1;r<n;r++)
	{
		// cout << "l = " << l << " and r = " << r << endl;
		int data[2] = {};
		Compute(input,n,l,r,data);
		increase[r] = data[0];
		decrease[r] = data[1];
	}
	*/

	Alternate(input,increase,decrease,n);

	// Print_Array(increase,n);
	// cout << endl;
	// Print_Array(decrease,n);

	while(q--)
	{
		int l,r;
		cin >> l >> r;

		l--;
		r--;
		
		int i=0,d=0;

		if ((increase[l] == increase[l+1]) && (decrease[l] == decrease[l+1]))
		{
			if (input[l] < input[l+1])
			{
				i = 1;
				d = 0;
			}

			else
			{
				i = 0;
				d = 1;
			}
		}

		i += (increase[r] - increase[l]);
		d += (decrease[r] - decrease[l]);

		if (i == d)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}