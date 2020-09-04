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

int Compute(vector<int> &low, vector<int> &high, int n){
    vec1d(dp,int,n+1,0);
    
    dp[0] = 0;
    dp[1] = high[0];

    fr(i,2,n){
        dp[i] = max(dp[i-2] + high[i-1], dp[i-1] + low[i-1]);
    }
    return dp[n];
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n;
        cin >> n;
        vec1d(low,int,n,0);
        vec1d(high,int,n,0);
        Input_Vector(high,n);
        Input_Vector(low,n);

        cout << Compute(low,high,n) << endl;
    }
}