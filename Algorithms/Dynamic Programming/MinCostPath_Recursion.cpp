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

void Input_Matrix(vector<vector<int>> &v, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j=0; j<n; j++)
		{
			cin >> v[i][j];
		}
	}
}

int computeCost(vector<vector<int>> &v, int m, int n)
{
	// Path starts from (0,0)
	if (n<0 || m<0)
		return INT_MAX;
	else if (m==0 && n==0)
		return v[m][n];
	else
		return v[m][n] + min(min(computeCost(v,m-1,n),computeCost(v,m,n-1)),computeCost(v,m-1,n-1));
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int> (n,0));
	Input_Matrix(v,m,n);

	cout << computeCost(v, m-1, n-1) << endl;
}