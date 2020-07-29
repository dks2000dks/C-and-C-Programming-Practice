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

int LIS(vector<int> &v){
	int n = v.size();
	vector<int> dp(n,-1);
	dp[0] = 1;

	fr(i,1,n-1){
		dp[i] = 1;
		fr(j,0,i-1){
			if (v[j] < v[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	return *max_element(dp.begin(),dp.end());
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);

        fr(i,0,n-1){
            cin >> v[i];
        }

        cout << LIS(v) << endl;
    }
}