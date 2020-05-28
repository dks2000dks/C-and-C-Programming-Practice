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

int main()
{
	int n;
	cin >> n;
	std::vector<int> elements(n);
	Input_Vector(elements,n);

	
}