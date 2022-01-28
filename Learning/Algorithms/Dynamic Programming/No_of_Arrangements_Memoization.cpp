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
#define fr(i, a, b) for (int i=a; i<=b; i++)

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

// Initialising values to NULL
void _initialise()
{
	int i;
	fr(i,0,MAX-1)
	{
		table[i] = NIL;
	}
}

int Arrangements(vector<int> &inputs, int n)
{
	if (n<0)
		return 0;

	else if (n==0)
		return 1;

	if (table[n] != -1)
		return table[n];

	int output=0;
	
	fr(i,0,inputs.size()-1)
	{
		output += Arrangements(inputs,n-inputs[i]);
	}

	table[n] = output;
	return table[n];
}

int main()
{
	int n;
	cin >> n;

	_initialise();

	int p;
	cin >> p;
	vector<int> values(p);
	// '1' is considered as default value.
	Input_Vector(values,p);
	sort(values.begin(),values.end());

	cout << "Number of Arrangements are " << Arrangements(values,n) << endl;
	return 0;
}