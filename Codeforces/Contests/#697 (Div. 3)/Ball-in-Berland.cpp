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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int Compute(vector<vector<int>> P, int i, int j, int a, int b, int k){
    int count = k + P[i][j];
    
    int s1 = 0;
    fr(r,0,a-1){
        s1 += P[r][j];
    }

    int s2 = 0;
    fr(c,0,b-1){
        s2 += P[i][c];
    }

    return count - s1 -  s2;
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int Print_Matrix(vector< vector<int>> &v, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,k;
        cin >> a >> b >> k;

        vec1d(as,int,k,0);
        Input_Vector(as,k);

        vec1d(bs,int,k,0);
        Input_Vector(bs,k);

        vec2d(P,int,a,b,0);
        fr(i,0,k-1){
            P[as[i]-1][bs[i]-1] = 1;
        }
        
        int count  = 0;
        fr(l,0,k-1){
            count += Compute(P,as[l]-1,bs[l]-1,a,b,k);
        }

        cout << count/2 << endl;
    }
}