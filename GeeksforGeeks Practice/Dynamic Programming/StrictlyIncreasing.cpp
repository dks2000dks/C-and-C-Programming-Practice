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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int Compute(vector<int> &v, int n){
    vec1d(dp,int,n,1);
    int m = INT_MIN;

    fr(i,1,n-1){
        fr(j,0,i-1){
            if (v[j] < v[i] && (i-j) <= (v[i] - v[j]))
                dp[i] = max(dp[i],dp[j] + 1);
        }
        m = max(m,dp[i]);
    }
    return n-m;
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n) << endl;
    }
}