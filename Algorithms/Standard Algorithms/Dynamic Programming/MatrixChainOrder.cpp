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

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int Compute(vector<int> &v, int n){
    vec2d(dp,int,n,n,0);

    fr(l,2,n-1){
        fr(i,1,n-l){
            int j = i+l-1;
            dp[i][j] = INT_MAX;
            fr(k,i,j-1){
                dp[i][j] = min( dp[i][j], (dp[i][k] + dp[k+1][j] + (v[i-1] * v[k] * v[j])) );
            }
        }
    }
    return dp[1][n-1];
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n) << endl;
    }
}