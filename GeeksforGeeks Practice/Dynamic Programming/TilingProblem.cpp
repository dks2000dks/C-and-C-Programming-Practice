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

int Compute(int n, int m){
    vec1d(dp,int,n+1,0);
    int p = pow(10,9) + 7;

    fr(i,0,n){
        if (i > m)
            dp[i] = (dp[i-1] + dp[i-m])%p;
        else if (i<m || i==1)
            dp[i] = 1;
        else{
            dp[i] = 2;
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        cout << Compute(n,m) << endl;
    }
}