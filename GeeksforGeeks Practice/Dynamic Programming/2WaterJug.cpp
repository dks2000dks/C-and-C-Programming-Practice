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

int Compute(int n, int m, int k){
    vec1d(dp,int,k+1,INT_MAX);
    dp[0] = 0;

    fr(i,1,k){
        if (i-n >= 0){
            if (dp[i-n] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-n]);
        }

        if (i-m >= 0){
            if (dp[i-m] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i-m]);
        }

        if (i-abs(n-m) >= 0){
            if (dp[i-abs(n-m)] != INT_MAX)
                dp[i] = min(dp[i], 3 + dp[i-abs(n-m)]);
        }
    }
    if (dp[k] == INT_MAX)
        return -1;
    return dp[k];
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,m,k;
        cin >> n >> m >> k;
        cout << Compute(n,m,k) << endl;
    }
}