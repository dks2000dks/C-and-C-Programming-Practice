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

int Compute(vector<int> &v){
    int n = v.size();

    vec1d(dp,ll,n,INT_MAX);
    dp[0] = 0;

    fr(i,0,n-2){
        int s = v[i];
        int jump;
        if (v[i] != 0){
            jump = 1;
        }
        else{
            jump = INT_MAX;
        }

        fr(j,i+1,i+s){
            if (j<=n-1){
                dp[j] = min(dp[j],dp[i]+jump);
            }
        }
    }

    if (dp[n-1] >= INT_MAX){
        return -1;
    }
    else{
        return dp[n-1];
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        cout << Compute(v) << endl;
    }
}
