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

int Print_Matrix(vector< vector<int>> &v, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int Compute(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    if (n==m)
        return (s1==s2);

    vec2d(dp,int,n+1,m+1,0);
    dp[0][0] = 1;

    fr(i,1,n){
        fr(j,0,m){
            if (j==0){
                dp[i][j] = 1;
            }

            else{
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s1,s2;
        cin >> s1;
        cin >> s2;
        cout << Compute(s1,s2) << endl;
    }
}