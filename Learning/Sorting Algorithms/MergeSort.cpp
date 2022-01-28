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

vector<int> SubVector(vector<int> const &v, int m, int n)
{
	auto first = v.begin() + m;
	auto last = v.begin() + n + 1;
	vector<int> vector(first, last);
	return vector;
}

vector<int> MergeSort(vector<int> const &v, int n)
{
	int mid = n/2;
	int x;
	vector<int> output;

	if (n > 1)
	{
		vector<int> input1 = SubVector(v,0,mid-1);
		vector<int> input2 = SubVector(v,mid,n-1);
		
		int n1 = input1.size();
		int n2 = input2.size();
		
		vector<int> output1 = MergeSort(input1,n1);
		vector<int> output2 = MergeSort(input2,n2);
		
		int i=0,j=0;
		while (i<n1 && j<n2)
		{
			if (output1[i] < output2[j])
			{
				x = output1[i];
				i++;
			}
			
			else
			{
				x = output2[j];
				j++;
			}

			output.push_back(x);
		}

		while(i<n1 && j>=n2)
		{
			output.push_back(output1[i]);
			i++;
		}

		while (i>=n1 && j<n2)
		{
			output.push_back(output2[j]);
			j++;
		}
		
	}

	else
	{
		output = v;
	}

	return output;
}

int main()
{
	int n;
	cin >> n;

	vector<int> v;

	Input_Vector(v,n);
	vector<int> o = MergeSort(v,n);
	Print_Vector(o,n);
}