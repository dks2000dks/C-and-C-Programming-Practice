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

int Process(int l, unordered_set<int> &v){
    vec1d(dp,int,l+1,0);

    fr(i,1,l){
        if (v.find(i) != v.end()){
            dp[i] = 1;
        }

        for(auto it = v.begin(); it !=v.end(); ++it){
            int a = i - *it;
            int b = *it;

            // cout << i << " " << a << " " << b << endl;

            if (a>0 && b>0 && dp[b] > 0 && dp[a] > 0){
                dp[i] = max(dp[i], dp[b] + dp[a]);
                //cout << i << " " << *it << " " << dp[i] << endl;   
            }
        }
    }

    return dp[l];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l;
        cin >> l;

        unordered_set<int> v;
        int x;
        fr(i,0,2){
            cin >> x;
            v.insert(x);
        }

        cout << Process(l,v) << endl;
    }
}