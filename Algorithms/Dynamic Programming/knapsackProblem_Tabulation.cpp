//0-1 Knapsnack Problem
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

int compute(vector<int> &cost, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n+1,vector<int> (w+1,0));

	fr(i,1,n){
		fr(j,1,w){
			if (j-weights[i-1] >= 0)
				dp[i][j] = max(dp[i-1][j], cost[i-1] + dp[i-1][j-weights[i-1]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(){
	int n,w;
	cin >> n >> w;
	vector<int> cost(n),weights(n);
	Input_Vector(cost,n);
	Input_Vector(weights,n);
	cout << compute(cost,weights,n,w) << endl;
}