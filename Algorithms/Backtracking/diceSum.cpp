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
#include <numeric>
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

void diceSum(int n,vector<int> &soFar,int desiredSum)
{
	if (n==0)
	{
		int sum = accumulate(soFar.begin(),soFar.end(),0);
		if (sum == desiredSum)
			Print_Vector(soFar,soFar.size());
	}

	else if (n>0)
	{
		FR(i,1,6)
		{
			soFar.push_back(i);
			diceSum(n-1,soFar,desiredSum);
			soFar.pop_back();
		}
	}
}

// Optimization
/*
– Sometimes the current sum is already too high.
	(Even rolling 1 for all remaining dice would exceed the desired sum.)
– Sometimes the current sum is already too low.
	(Even rolling 6 for all remaining dice would fall short of the desired sum.)
– The code must re-compute the sum many times.
	(1+1+1 = ..., 1+1+2 = ..., 1+1+3 = ..., 1+1+4 = ..., ...)
	- It can be understood like optimising computing '1+1' in above case.
*/
void diceSumOpt1(int n,vector<int> &soFar,int sum,int desiredSum)
{
	if (n==0)
	{
		if (sum == desiredSum)
			Print_Vector(soFar,soFar.size());
	}

	else if (sum+1*n <= desiredSum && sum+6*n >= desiredSum)
	{
		FR(i,1,6)
		{
			soFar.push_back(i);
			diceSumOpt1(n-1,soFar,sum+i,desiredSum);
			soFar.pop_back();
		}
	}
}

// Printing Unique Sets
void diceSumOpt2(int n,vector<int> &soFar,int sum,int desiredSum,int minDieValue)
{
	if (n==0)
	{
		if (sum == desiredSum)
			Print_Vector(soFar,soFar.size());
	}

	else if (sum+1*n <= desiredSum && sum+6*n >= desiredSum)
	{
		FR(i,minDieValue,6)
		{
			soFar.push_back(i);
			diceSumOpt2(n-1,soFar,sum+i,desiredSum,i);
			soFar.pop_back();
		}
	}
}

int main()
{
	int n,requiredsum;
	cin >> n >> requiredsum;

	std::vector<int> v;

	//diceSum(n,v,requiredsum);
	//diceSumOpt1(n,v,0,requiredsum);
	diceSumOpt2(n,v,0,requiredsum,1);
}