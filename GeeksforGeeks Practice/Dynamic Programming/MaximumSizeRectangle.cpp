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

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int maxHist(vector<int> &a) {
        int m = a.size(), ans=0;
        stack<int> s;
        for(int j=0; j<m; j++) {
            if(s.empty() || a[s.top()]<a[j]) s.push(j);
            else {
                while(!s.empty() && a[s.top()]>=a[j]) {
                    int ht= a[s.top()]; s.pop();
                    if(!s.empty()) ans= max(ans, (j-s.top()-1)*ht);
                    else ans= max(ans, j*ht);
                }
                s.push(j);
            }
        }
        while(!s.empty()) {
            int ht= a[s.top()]; s.pop();
            if(!s.empty()) ans= max(ans, (m-s.top()-1)*ht);
            else ans= max(ans, m*ht);
        }
    return ans;
}

int Compute(vector<vector<int>> &v, int n, int m){
    int o = maxHist(v[0]);

    fr(i,1,n-1){
        fr(j,0,m-1){
            if (v[i][j])
                v[i][j] += v[i-1][j];
        }
        o = max(o,maxHist(v[i]));
    }

    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec2d(v,int,n,m,0);
        Input_Matrix(v,n,m);
        cout << Compute(v,n,m) << endl;
    }
}