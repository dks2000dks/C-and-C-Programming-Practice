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

int MaximumSum(int n){
    vec1d(dp,int,n+1,0);

    fr(i,0,n){
        dp[i] = i;
    }

    fr(i,1,n){
        dp[i] = max(dp[i], dp[i/2] + dp[i/3] + dp[i/4]);
    }

    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << MaximumSum(n) << endl;
    }
}