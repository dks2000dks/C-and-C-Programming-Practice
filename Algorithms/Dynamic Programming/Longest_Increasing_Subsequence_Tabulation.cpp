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

int LIS(vector<int> &elements, int start, int end)
{
	int n = end-start+1;
	std::vector<int> f(n,-1);
	f[0] = 1;

	FR(i,1,n-1)
	{
		f[i] = 1;
		FR(j,0,i)
		{
			if (elements[start+j] < elements[start+i] && f[i] < f[j] + 1)
				f[i] = f[j] + 1;
		}
	}

	return *max_element(f.begin(),f.end());
}

int main()
{
	int n;
	cin >> n;
	std::vector<int> elements(n);
	Input_Vector(elements,n);

	cout <<  LIS(elements,0,n-1) << endl;
}