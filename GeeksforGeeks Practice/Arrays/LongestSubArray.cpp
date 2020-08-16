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

int Compute(vector<int> &v, int n){
    vec1d(dp,int,n,0);
    int count = 1;

    fr(i,0,n-1){
        if (v[i] >= 0){
            dp[i] = count;
            count++;
        }
        else{
            count = 1;
            dp[i] = 0;
        }
    }

    /*
    fr(i,0,n-1) cout << dp[i] << " ";
    cout << endl;
    */

    return *max_element(dp.begin(),dp.end());
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        cout << Compute(v,n) << endl;
    }
}