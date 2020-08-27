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

int Print_Matrix(vector< vector<int>> &mat, int n, int m){
	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


int Compute(vector<vector<int>> &v, int n, int m){
    vec2d(dp,int,n,m,0);
    int side = 0;
    fr(i,0,n-1){
        fr(j,0,m-1){
            if (i==0 || j==0){
                dp[i][j] = v[i][j];
                if (dp[i][j])
                    side = max(side,dp[i][j]);
            }
            else{
                if (v[i][j])
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]),dp[i-1][j-1]);
                side = max(side,dp[i][j]);
            }
        }
    }

    //Print_Matrix(dp,n,m);

    return side;

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec2d(v,int,n,m,0);
        Input_Matrix(v,n,m);
        //Print_Matrix(v,n,m);
        //cout << endl;

        cout << Compute(v,n,m) << endl;
    }
}