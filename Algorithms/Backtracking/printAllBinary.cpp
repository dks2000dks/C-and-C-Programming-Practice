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

void printAllBinary(int digitsleft, string soFar)
{
	if (digitsleft==0)
		cout << soFar << endl;
	else
	{
		printAllBinary(digitsleft-1,soFar+'0');
		printAllBinary(digitsleft-1,soFar+'1');
	}
}
int main()
{
	int n;
	cin >> n;

	printAllBinary(n, "");
}