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

void Print_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

void diceRolls(int n,vector<int> &soFar)
{
	if (n==0)
		Print_Vector(soFar,soFar.size());

	else if (n>0)
	{
		n--;
		FR(i,1,6)
		{
			soFar.push_back(i);
			diceRolls(n,soFar);
			soFar.pop_back();
		}
	}
}

int main()
{
	int n;
	cin >> n;
	std::vector<int> v;

	diceRolls(n,v);
}