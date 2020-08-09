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

int RodCutting(vector<int> &v, int n){
    vector<int> dp = v;
    dp.insert(dp.begin(),0);

    fr(i,2,n){
        fr(j,1,(i/2)){
            dp[i] = max(dp[i],dp[j] + dp[i-j]);
        }
    }

    return dp[n];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << RodCutting(v,n) << endl;
    }
}