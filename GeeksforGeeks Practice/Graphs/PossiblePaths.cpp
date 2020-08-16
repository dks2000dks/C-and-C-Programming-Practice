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

int CountPaths(vector<vector<int>> &adjm, int s, int d, int k){
    int V = adjm.size();
    int Count[V][V][k+1];

    fr(e,0,k){
        fr(i,0,V-1){
            fr(j,0,V-1){

                Count[i][j][e] = 0;

                if (e == 0 && i==j)
                    Count[i][j][e] = 1;
                
                if (e==1 && adjm[i][j])
                    Count[i][j][e] = 1;

                if (e>1){
                    fr(a,0,V-1){
                        if (adjm[i][a])
                            Count[i][j][e] += Count[a][j][e-1];
                    }
                }
            }
        }
    }
    return Count[s][d][k];
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int V;
        cin >> V;
        vec2d(adjm,int,V,V,0);
        Input_Matrix(adjm,V,V);

        int s,d,k;
        cin >> s >> d >> k;

        cout << CountPaths(adjm,s,d,k) << endl;
    }
}