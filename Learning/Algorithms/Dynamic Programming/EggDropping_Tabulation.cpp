// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
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

int compute(int e, int f){
	vec2d(dp,e+1,f+1,0);

	fr(i,0,f)
		dp[1][i] = i;
	fr(i,1,e)
		dp[i][1] = 1;

	fr(i,2,e){
		fr(j,2,f){
			dp[i][j] = INT_MAX;
			fr(x,1,j){
				dp[i][j] = min(dp[i][j],1+max(dp[i-1][x-1],dp[i][j-x]));
			}
		}
	}
	return dp[e][f];
}

int main(){
	int e,f;
	cin >> e >> f;
	cout << compute(e,f) << endl;
}