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

int UnlimitedKnapsack(vector<int> values, vector<int> weights, int cap){
    int n = values.size();

    vec1d(dp,int,cap+1,0);

    fr(i,1,cap){
        fr(j,0,n-1){
            if (i-weights[j] >= 0)
                dp[i] = max(dp[i], dp[i-weights[j]] + values[j]);
        }
    }

    return dp[cap];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,cap;
        cin >> n >> cap;

        vec1d(values,int,n,0);
        vec1d(weights,int,n,0);

        Input_Vector(values,n);
        Input_Vector(weights,n);

        cout << UnlimitedKnapsack(values,weights,cap) << endl;
    }
}