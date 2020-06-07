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

void Print_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

int diceCombinations(int n){
	std::vector<int> v(n+1);
	int limit = pow(10,9) + 7;

	v[0] = 0;
	int sum;

	fr(i,1,n){
		sum = 0;
		fr(j,i-6,i-1){
			if (j>=0){
				sum +=v[j];
				sum = sum%limit;
			}
		}
		if (i<=6)
			v[i] = sum+1;
		else
			v[i] = sum;
	}

	return v[n];
}

int main()
{
	int n;
	cin >> n;

	cout << diceCombinations(n) << endl; 
}