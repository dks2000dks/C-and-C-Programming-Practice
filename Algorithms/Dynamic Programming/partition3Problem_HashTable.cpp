// https://www.geeksforgeeks.org/partition-problem-dp-18/
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
#include <unordered_map>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec2d(v,n,m,init) vector<vector<bool>> v(n, vector<bool>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

// Helper function for solving 3 partition problem
// It return true if there exists three subsets with given sum
bool subsetSum(vector<int> &S, int n, int a, int b, int c, auto &lookup)
{
	// return true if subset is found
	if (a == 0 && b == 0 && c == 0)
		return true;

	// base case: no items left
	if (n < 0)
		return false;

	// construct an unique map key from dynamic elements of the input
	string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
				"|" + to_string(n);

	// if sub-problem is seen for the first time, solve it and
	// store its result in a map
	if (lookup.find(key) == lookup.end())
	{
		// Case 1. current item becomes part of first subset
		bool A = false;
		if (a - S[n] >= 0)
			A = subsetSum(S, n - 1, a - S[n], b, c, lookup);

		// Case 2. current item becomes part of second subset
		bool B = false;
		if (!A && (b - S[n] >= 0))
			B = subsetSum(S, n - 1, a, b - S[n], c, lookup);

		// Case 3. current item becomes part of third subset
		bool C = false;
		if ((!A && !B) && (c - S[n] >= 0))
			C = subsetSum(S, n - 1, a, b, c - S[n], lookup);

		// return true if we get solution
		lookup[key] = A || B || C;
	}

	// return the subproblem solution from the map
	return lookup[key];
}

// Function for solving 3-partition problem. It return true if given
// set S[0..n-1] can be divided into three subsets with equal sum
bool partition(vector<int> &S, int n)
{
	if (n < 3)
		return false;

	// create a map to store solutions of subproblems
	unordered_map<string, bool> lookup;

	// get sum of all elements in the set
	int sum = accumulate(S.begin(), S.end(), 0);

	// return true if sum is divisible by 3 and the set S can
	// be divided into three subsets with equal sum
	return !(sum % 3) && subsetSum(S, n - 1, sum/3, sum/3, sum/3, lookup);
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	Input_Vector(v,n);
	cout << partition(v,n) << endl;
}