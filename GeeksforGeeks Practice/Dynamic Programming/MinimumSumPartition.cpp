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

int MinDifference(vector<int> &v){
    int sum = accumulate(v.begin(),v.end(),0);
    int n = v.size();

    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));

    fr(i,0,n){
        dp[i][0] = 1;
    }

    fr(j,1,sum){
        dp[0][j] = 0;
    }

    fr(i,1,n){
        fr(j,1,sum){
            if (j-v[i-1] >= 0){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int diff = INT_MAX;

    for(int j=sum/2;j>=0;j--){
        if (dp[n][j]){
            diff = (sum-j)-j;
            break;
        }
    }

    return diff;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << MinDifference(v) << endl;
    }
}