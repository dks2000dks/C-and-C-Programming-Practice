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

int Compute(vector<int> &values, vector<int> &weights, int cap){
    int n = values.size();

    vec2d(dp,int,n+1,cap+1,0);

    fr(i,0,n){
        fr(j,0,cap){
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (weights[i-1] <= j){
                dp[i][j] = max(dp[i-1][j-weights[i-1]]+values[i-1], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][cap];
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int cap;
        cin >> cap;

        vec1d(values,int,n,0);
        Input_Vector(values,n);

        vec1d(weights,int,n,0);
        Input_Vector(weights,n);

        cout << Compute(values,weights,cap) << endl;

    }
}