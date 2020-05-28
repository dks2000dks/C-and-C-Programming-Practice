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

int Fibonacci(int n)
{
	int f[n+1];
	f[0] = 0;
	f[1] = 1;

	FR(i,2,n)
	{
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

int main()
{
	int n=40;
	cout << "Fibonacci Number is " << Fibonacci(n) << endl;
	return 0;
}