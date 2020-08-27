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

ll Compute(int n){
    if (n>3){
        vec1d(dp,ll,n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;

        fr(i,4,n){
            dp[i] = dp[i-1] + dp[i-4];
        }
        
        return dp[n];
    }

    else{
        return 1;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << Compute(n) << endl;
    }
}