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

int Max_Matrix(vector< vector<int>> &mat, int n, int m){
    int mini = INT_MIN;

	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			mini = max(mini,mat[i][j]);
		}
	}

    return mini;
}

int Compute(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vec2d(dp,int,n+1,m+1,0);

    fr(i,0,n){
        fr(j,0,m){
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    return Max_Matrix(dp,n+1,m+1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1;
        cin >> s2;

        cout << Compute(s1,s2) << endl;
    }
}