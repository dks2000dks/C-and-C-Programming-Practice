// Dynamic Programming
// Overlapping Subproblem

#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
#define FR(i, a, b) for (int i=a; i<=b; i++)

#define NIL -1
#define MAX 100

int table[MAX];

void Input_Vector(vector<int> &array, int size)
{
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int Arrangements(vector<int> &inputs, int n)
{
	int table[n+1];

	table[0] = 1;

	FR (i,1,n)
	{
		int output=0;

		FR(j,0,inputs.size()-1)
		{
			if (i-inputs[j] >= 0)
				output += table[i-inputs[j]];
		}

		table[i] = output;
	}

	return table[n];
}

int main()
{
	int n;
	cin >> n;

	int p;
	cin >> p;
	vector<int> values(p);
	// '1' is considered as default value.
	Input_Vector(values,p);
	sort(values.begin(),values.end());

	cout << "Number of Arrangements are " << Arrangements(values,n) << endl;
	return 0;
}