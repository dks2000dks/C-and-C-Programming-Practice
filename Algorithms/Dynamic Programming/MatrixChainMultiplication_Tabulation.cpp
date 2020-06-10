// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
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

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int computeoperations(vector<int> &dims,int n){
	vector<vector<int>> dp(n, vector<int>(n,0));

	fr(l,2,n-1){
		fr(i,1,n-l){
			int j = i+l-1;
			dp[i][j] = INT_MAX;
			fr(k,i,j-1){
				dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+ dims[i-1]*dims[k]*dims[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main() {
	int n;
	cin >> n;
	std::vector<int> dims(n,0);
	Input_Vector(dims,n);
	cout << computeoperations(dims,n) << endl;
}
