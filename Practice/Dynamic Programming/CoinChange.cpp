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

int CoinChange(int C, vector<int> &v){
    int m = v.size();
    vec2d(dp,int,C+1,m,0);

    int x,y;

    fr(i,0,m-1){
        dp[0][i] = 1;
    }

    fr(i,1,C){
        fr(j,0,m-1){
            if (i-v[j] >= 0){
                x = dp[i-v[j]][j];
            }
            else{
                x = 0;
            }

            if (j>=1){
                y = dp[i][j-1];
            }
            else{
                y = 0;
            }

            dp[i][j] = x+y;
        }
    }

    return dp[C][m-1];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        int C;
        cin >> C;

        cout << CoinChange(C,v) << endl;
    }
}