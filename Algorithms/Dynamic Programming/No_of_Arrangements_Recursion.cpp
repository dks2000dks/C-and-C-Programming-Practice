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
typedef long long int ll;
#define FR(i, a, b) for (int i=a; i<=b; i++)

void Print_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

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
	if (n<0)
		return 0;
	else if (n==0)
		return 1;

	int output=0;
	
	FR(i,0,inputs.size()-1)
	{
		output += Arrangements(inputs,n-inputs[i]);
	}
	return output;
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