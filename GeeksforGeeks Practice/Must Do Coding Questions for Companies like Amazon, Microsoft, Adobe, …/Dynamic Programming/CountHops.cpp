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

int CountHops(int n){
    vec1d(dp,int,n+1,0);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    fr(i,4,n){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
       int n;
       cin >> n;

       cout << CountHops(n) << endl; 
    }
}