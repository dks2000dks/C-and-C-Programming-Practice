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

int compute(vector<int> &cost,vector<int> &pages, int n, int x){

	vector<vector<int>> dp(n+1,vector<int>(x+1,0));
	fr(i,1,n){
		fr(j,0,x){
			dp[i][j] = dp[i-1][j];
			if (j-cost[i-1] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-cost[i-1]]+pages[i-1]);
			}
		}
	}

	return dp[n][x];
}

int main(){
	int n,x;
	cin >> n >> x;
	vector<int> cost(n);
	vector<int> pages(n);
	Input_Vector(cost,n);
	Input_Vector(pages,n);

	cout << compute(cost,pages,n,x) << endl;
}