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

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int Compute(vector<vector<int>> &v, int n){
    vec2d(dp,int,n,n,0);

    fr(i,0,n-1){
        fr(j,0,n-1){
            if (i==0)
                dp[i][j] = v[i][j];

            else if (j==0)
                dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + v[i][j];

            else if (j!= n-1){
                dp[i][j] = v[i][j] + max(max(dp[i-1][j-1],dp[i-1][j+1]), dp[i-1][j]);
            }
            else{
                dp[i][j] = v[i][j] + max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    return *max_element(dp[n-1].begin(),dp[n-1].end());
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec2d(v,int,n,n,0);
        Input_Matrix(v,n,n);

        cout << Compute(v,n) << endl;
    }
}