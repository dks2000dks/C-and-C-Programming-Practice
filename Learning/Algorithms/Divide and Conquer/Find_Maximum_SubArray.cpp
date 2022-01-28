#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;

void Input_Vector(vector<int> &array, int size)
{
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		array.push_back(x);
	}
}

void Print_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

vector<int> Max_Crossing_SubArray(vector<int> const &v, int l, int m, int h)
{
	int sum;
	vector<int> output;

	int leftsum = INT_MIN;
	int ml;
	sum=0;
	for (int i=m;i>=l;i--)
	{
		sum += v[i];
		if (sum > leftsum)
		{
			leftsum = sum;
			ml = i;
		}
	}

	int rightsum = INT_MIN;
	int mr;
	sum=0;
	for (int i=m+1;i<=h;i++)
	{
		sum += v[i];
		if (sum > rightsum)
		{
			rightsum = sum;
			mr = i;
		}
	}

	output.push_back(ml);
	output.push_back(mr);
	output.push_back(leftsum + rightsum);

	return output;
}

vector<int> Max_SubArray(vector<int> const &v, int l, int h)
{
	vector<int> output;
	if (h==l)
	{
		output.push_back(l);
		output.push_back(h);
		output.push_back(v[l]);
	}

	else
	{
		int m = (l+h)/2;
		
		vector<int> left = Max_SubArray(v,l,m);
		vector<int> right = Max_SubArray(v,m+1,h);
		vector<int> cross = Max_Crossing_SubArray(v,l,m,h);

		if (left[2] >= right[2] && left[2] >= cross[2])
		{
			output =  left;
		}

		else if (right[2] >= left[2] && right[2] >= cross[2])
		{
			output =  right;
		}

		else
		{
			output =  cross;
		}
	}

	return output;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	Input_Vector(v,n);
	int l = 0;
	int h = n-1;
	vector<int> o = Max_SubArray(v,l,h);
	Print_Vector(o,o.size());
}