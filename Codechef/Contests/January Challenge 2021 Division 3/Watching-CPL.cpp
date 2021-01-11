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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int Print_Matrix(vector<vector<bool>> &v, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int Compute(vector<int> v, int k){
    vec2d(dp,bool,v.size()+1,k,false);
    int sum = 0;
    int p = INT_MAX;

    fr(i,1,v.size()){
        fr(j,0,k-1){
            if (j==0)
                dp[i][j] = true;
            else{
                if (j - v[i-1] >= 0)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        sum += v[i-1];
        fr(j,0,k-1){
            if (dp[i-1][j]){
                if (j+v[i-1] >= k)
                    p = min(p,j+v[i-1]);
            }
        }
        if (sum - p >= k)
            return i;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        sort(v.begin(),v.end(),greater<int>());
        cout << Compute(v,k) << endl;
    }
}