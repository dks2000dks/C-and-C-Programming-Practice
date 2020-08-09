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

int LCS3(string s1, string s2, string s3, int l, int m, int n){
    int dp[l+1][m+1][n+1] = {};

    fr(i,1,l){
        fr(j,1,m){
            fr(k,1,n){
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }

    return dp[l][m][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l,m,n;
        cin >> l >> m >> n;

        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;

        cout << LCS3(s1,s2,s3,l,m,n) << endl;
    }
}