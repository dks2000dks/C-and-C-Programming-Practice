// https://www.geeksforgeeks.org/partition-problem-dp-18/
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
#define vec2d(v,n,m,init) vector<vector<bool>> v(n, vector<bool>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

bool Result(vector<int> &v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	if (sum%2 != 0)
		return false;
	else{
		int partialsum = sum/2;
		vec2d(dp,n+1,partialsum+1,false);

		fr(i,0,n)
			dp[i][0] = true;

		fr(j,1,partialsum)
			dp[0][j] = false;

		fr(i,1,n){
			fr(j,1,partialsum){
				if (j-v[i] >= 0)
					dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
			}
		}
		return dp[n][partialsum];
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	Input_Vector(v,n);
	cout << Result(v,n) << endl;
}