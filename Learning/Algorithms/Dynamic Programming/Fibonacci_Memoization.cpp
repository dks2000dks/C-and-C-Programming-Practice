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

// Initialising values to NULL
void _initialise()
{
	int i;
	fr(i,0,MAX-1)
	{
		table[i] = NIL;
	}
}

// Assign Values to table
int Fibonacci(int n)
{
	if (table[n] == NIL)
	{
		if (n <= 1)
			table[n] = n;
		else
			table[n] = Fibonacci(n-1) + Fibonacci(n-2);
	}
	return table[n];
}

int main()
{
	int n=40;
	_initialise();
	cout << "Fibonacci Number is " << Fibonacci(n) << endl;
	return 0;
}
