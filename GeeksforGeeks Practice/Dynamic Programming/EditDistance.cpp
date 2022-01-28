#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int EditDistance(const string &str1, const string &str2, int m, int n){
	vec2d(dp,int,m+1,n+1,0);

	fr(i,0,m){
		fr(j,0,n){
			if (i==0)
				dp[i][j] = j;
			else if (j==0)
				dp[i][j] = i;
			else if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
		}
	}

	return dp[m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        string str1;
        string str2;
        cin >> str1;
        cin >> str2;

        cout << EditDistance(str1, str2, m ,n) << endl;
    }
}