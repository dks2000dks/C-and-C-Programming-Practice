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

int ReachScore(int n){
    
    vector<int> v = {3,5,10};
    int m = v.size();

    vec2d(dp,int,n+1,m,0);

    fr(i,0,n){
        fr(j,0,m-1){
            if (i==0)
                dp[i][j] = 1;

            else{
                int x = 0, y = 0;
                if (i-v[j] >= 0){
                    x = dp[i-v[j]][j];
                }
                if (j>=1){
                    y = dp[i][j-1];
                }
                dp[i][j] = x+y;
            }
        }
    }

    return dp[n][m-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        cout << ReachScore(n) << endl;
    }
}