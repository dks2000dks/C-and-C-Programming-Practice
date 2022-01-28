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
	vector<vector<int>> matrix(m+1,vector<int> (n+1,0));
	matrix[0][0] = v[0][0];
	fr(i,1,m){
		matrix[i][0] = v[i][0] + matrix[i-1][0];
	}
	fr(i,1,n){
		matrix[0][i] = v[0][i] + matrix[0][i-1];
	}

	fr(i,1,m){
		fr(j,1,n){
			matrix[i][j] = v[i][j] + min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]);
		}
	}

	return matrix[m][n];
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int> (n,0));
	Input_Matrix(v,m,n);

	cout << computeCost(v, m-1, n-1) << endl;
}