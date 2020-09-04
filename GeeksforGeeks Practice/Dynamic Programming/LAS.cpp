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

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        
        vector<pair<int,int>> dp(n,make_pair(1,1));
        int o = 1;
        fr(i,1,n-1){
            fr(j,0,i-1){
                if (v[j] < v[i])
                    dp[i].second = max(dp[i].second, 1+dp[j].first);

                if (v[j] > v[i])
                    dp[i].first = max(dp[i].first, 1+dp[j].second);
            }
            o = max(o, max(dp[i].first, dp[i].second));
        }
        cout << o << endl;
    }
}