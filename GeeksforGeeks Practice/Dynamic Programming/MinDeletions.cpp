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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

int Compute(string s){
    int n = s.length();
    vec2d(dp, int, n + 1, n + 1, 0);

    string s1 = s;
    string s2 = s;
    reverse(s2.begin(),s2.end());

    fr(i,0,n){
        fr(j,0,n){
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            
            else if (s1[i-1] == s2[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            } 
        }
    }
    return s.length() - dp[n][n];
}

int main(){
    int T;
    cin >> T;

    while (T--){
        string s;
        cin >> s;
        cout << Compute(s) << endl;
    }
}