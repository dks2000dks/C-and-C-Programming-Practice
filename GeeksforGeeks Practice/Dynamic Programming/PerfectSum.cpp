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
#define p 1000000007;

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
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

int Compute(vector<int> &v, int n, int k){
    vec2d(dp,int,n+1,k+1,0);

    fr(i,0,n){
        fr(j,0,k){
            if (j==0)
                dp[i][j] = 1;
            else if (i==0)
                dp[i][j] = 0;

            else{
                dp[i][j] = dp[i-1][j];

                if (j - v[i-1] >= 0)
                    dp[i][j] = (dp[i][j] + dp[i-1][j-v[i-1]])%p;
            }
        }
    }
    //Print_Matrix(dp,n+1,k+1);
    return (dp[n][k])%p;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cin >> k;

        cout << Compute(v,n,k) << endl;
    }
}