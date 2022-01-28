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

int Process(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vec2d(dp,int,n+1,m+1,0);

    fr(i,0,n){
        fr(j,0,m){
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return n+m-dp[n][m];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string str1;
        string str2;
        cin >> str1 >> str2;

        cout << Process(str1,str2) << endl;
    }
}
