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

int Compute(vector<int> &v, int n, int k){
    vec1d(dp,int,k+1,INT_MAX);
    dp[0] = 0;

    fr(i,1,k){
        if (i<= n){
            if (v[i-1] != -1)
                dp[i] = v[i-1];
        }
            
        int l = i/2;
        fr(j,1,l){
            if (dp[j] != INT_MAX && dp[i-j] != INT_MAX)
                dp[i] = min(dp[i], dp[j] + dp[i-j]);
        }
    }

    if (dp[k] != INT_MAX)
        return dp[k];
    else
        return -1;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << Compute(v,n,k) << endl;
    }
}