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

int Result(vector<int> &v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	if (sum%2 != 0)
		return 0;
	else{
		int partialsum = sum/2;
		vec2d(dp,int,n+1,partialsum+1,0);

		fr(i,0,n)
			dp[i][0] = 1;

		fr(j,1,partialsum)
			dp[0][j] = 0;

		fr(i,1,n){
			fr(j,1,partialsum){
				if (j-v[i] >= 0)
					dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
			}
		}
		return dp[n][partialsum];
	}
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> v(n,0);
        Input_Vector(v,n);
        if (Result(v,n))
            cout << "YES" << endl;
        else{
            cout << "NO" << endl;
        }
    }
	
}