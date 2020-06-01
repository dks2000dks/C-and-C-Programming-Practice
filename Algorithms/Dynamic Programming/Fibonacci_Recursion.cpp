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
#define fr(i, a, b) for (int i=a; i<=b; i++)

int Fibonacci(int n)
{
	if (n<=1)
		return n;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
	int n=40;
	cout << "Fibonacci Number is " << Fibonacci(n) << endl;
	return 0;
}