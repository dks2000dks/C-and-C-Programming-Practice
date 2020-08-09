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

int MinimalMoves(string s){
    int n = s.length();

    vec1d(dp,int,n+1,INT_MAX);

    string s1 = "", s2 = "";

    dp[0] = 0;
    dp[1] = 1;
    s1 += s[0];

    fr(i,2,n){
        s1 += s[i-1];

        if ((s1.length() % 2 == 0) && (s1.substr(i/2,i/2) == s1.substr(0,i/2))){
                dp[i] = min(dp[i/2] + 1, dp[i-1] + 1);
        }

        else{
            dp[i] = dp[i-1] + 1;
        }
    }
    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        cout << MinimalMoves(s) << endl;
    }
}