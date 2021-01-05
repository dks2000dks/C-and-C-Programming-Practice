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

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int> compute(vector<int> v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	vec2d(dp,sum+1,n+1,false);
	dp[0][0] = true;

	fr(i,0,sum){
		fr(j,1,n){
			dp[i][j] = dp[i][j-1];
			if (i-v[j-1] >= 0 && dp[i-v[j-1]][j-1] == true)
				dp[i][j] = dp[i][j] || dp[i-v[j-1]][j-1];
		}
	}

	vector<int> output;
	fr(i,1,sum){
		if (dp[i][n] == true)
			output.push_back(i);
	}
	return output;
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	Input_Vector(v,n);
	vector<int> output = compute(v,n);
	cout << output.size() << endl;
	Print_Vector(output,output.size());
}