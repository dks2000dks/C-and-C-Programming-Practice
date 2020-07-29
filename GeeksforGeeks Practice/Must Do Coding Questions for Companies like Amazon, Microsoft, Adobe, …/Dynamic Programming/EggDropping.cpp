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

int Process(int n, int k){
    vec2d(dp,int,n+1,k+1,0);

    fr(j,0,k){
        dp[1][j] = j;
    }

    fr(i,0,n){
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    fr(i,2,n){
        fr(j,2,k){
            dp[i][j] = INT_MAX;
            fr(k,1,j){
                dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][k-1],dp[i][j-k]));
            }
        }
    }

    return dp[n][k];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        cout << Process(n,k) << endl;
    }
}