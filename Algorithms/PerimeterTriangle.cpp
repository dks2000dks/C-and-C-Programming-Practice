// https://www.geeksforgeeks.org/maximum-perimeter-triangle-from-array/

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

int MaxPerimeter(vector<int> v, int n)
{
	int peri=0;
	FR(i,0,n-3)
	{
		if (v[i] < v[i+1] + v[i+2])
			peri = max(peri, (v[i] + v[i+1] + v[i+2]));
	}

	return peri;
}

int main()
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	Input_Vector(v,n);
	sort(v.begin(),v.end(),greater<int>());

	cout << MaxPerimeter(v,n) << endl;
}