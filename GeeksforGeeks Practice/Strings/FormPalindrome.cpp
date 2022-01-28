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

int findMinInsertionsDP(string s, int l, int r){
    int n = r-l+1;
    vec2d(dp,int,n,n,0);

    int i,j;
    fr(gap,1,n-1){
        for(i=0, j=gap; j<n; ++i, ++j){
            dp[i][j] = (s[i] == s[j]) ? dp[i+1][j-1] : (min(dp[i][j-1],dp[i+1][j])+1);
        }
    }

    return dp[0][n-1];
}

int main(){
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        cout << findMinInsertionsDP(s,0,s.length()-1) << endl;
    }
    return 0;
}