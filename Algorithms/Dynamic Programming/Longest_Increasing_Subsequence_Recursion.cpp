/*
https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/
*/

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

void Input_Vector(vector<int> &array, int size)
{
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int LIS(vector<int> &elements, int start, int end, int *maxlength)
{
	if (end == start)
		return 1;

	int maxindexlength=1;
	int result = 1;

	FR(i,start,end-1)
	{
		result = LIS(elements,start,i,maxlength);
		if (elements[i] < elements[end] && result+1> maxindexlength)
		{
			maxindexlength  = result+1;
			//cout << maxindexlength << endl;
		}
	}

	if (*maxlength < maxindexlength)
		*maxlength = maxindexlength;

	return maxindexlength;
}

int main()
{
	int n;
	cin >> n;
	std::vector<int> elements(n);
	Input_Vector(elements,n);
	int maxlength = 1;
	LIS(elements,0,n-1,&maxlength);

	cout <<  maxlength << endl;
}