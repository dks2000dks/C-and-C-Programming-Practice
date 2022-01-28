//https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
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
#define vec2d(v,n,m,init) vector<vector<int>> v(n, vector<int>(m,init))

int binomialCoefficient(int n, int r){
	vec2d(dp,n+1,r+1,0);
	
	fr(i,0,n){
		dp[i][0] = 1;
	}

	fr(i,0,n){
		fr(j,1,r){
			if (i >= j && j>=1 && i >=1){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}
		}
	}
	return dp[n][r];
}

int main(){
	int n,r;
	cin >> n >> r;
	cout << binomialCoefficient(n,r) << endl;
}