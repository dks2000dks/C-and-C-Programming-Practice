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

int Compute(string s){
    int n = s.length();
    vec1d(dp,int,n+1,0);

    if (s[0] == '0')
        return 0;

    dp[0] = 1;
    dp[1] = 1;

    fr(i,2,n){
        if (s[i-1] > '0'){
            dp[i] += dp[i-1];
        }
            
        if (s[i-2] == '1' || s[i-2] == '2' && s[i-1] < '7'){
            dp[i] += dp[i-2];
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << Compute(s) << endl;
    }
}