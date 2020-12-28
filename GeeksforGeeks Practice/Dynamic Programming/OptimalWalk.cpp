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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

ll Compute(int n, int a, int b){
    vec1d(dp,ll,n+1,0);
    dp[0] = 0;

    fr(i,1,n){
        if (i%2 == 0){
            dp[i] = min(dp[i/2] + b, dp[i-1]+a);
        }
        else{
            dp[i] = min(min(dp[i/2] + b + a, dp[(i+1)/2] + b + a), dp[i-1]+a);
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,a,b;
        cin >> n >> a >> b;
        cout << Compute(n,a,b) << endl;
    }
}