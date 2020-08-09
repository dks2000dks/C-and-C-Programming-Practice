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

int LRS(string s){
    int n = s.length();
    vec2d(dp,int,n+1,n+1,0);

    fr(i,1,n){
        fr(j,1,n){
            if (s[i-1] == s[j-1] && i!= j){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;

        cin >> n;
        cin >> s;

        cout << LRS(s) << endl;
    }
}