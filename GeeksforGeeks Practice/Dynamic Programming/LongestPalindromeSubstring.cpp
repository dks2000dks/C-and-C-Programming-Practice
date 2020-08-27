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

string Compute(string s){
    string o = "";
    int n = s.length();

    vec2d(dp,bool,n,n,0);

    int maxLength = 1;

    fr(i,0,n-1){
        dp[i][i] = true;
    }

    int start = 0;
    fr(i,0,n-2){
        if (s[i] == s[i+1]){
            dp[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    fr(l,3,n){
        fr(i,0,n-l){
            int j = i+l-1;
            if (dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = true;

                if (l > maxLength){
                    start = i;
                    maxLength = l;
                }
            }
        }
    }

    fr(i,start,start+maxLength-1){
        o += s[i];
    }

    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        cout << Compute(s) << endl;
    }
}