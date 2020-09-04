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

int Compute(int n){    
    if (n <= 2)
        return n;

    vec1d(dp,int,n+1,0);
    int p = pow(10,9)+7;
    
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    fr(i,3,n){
        dp[i] = (dp[i-1] + dp[i-2])%p;
    }
    return (dp[n])%p;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        cout << Compute(n) << endl;
    }
}