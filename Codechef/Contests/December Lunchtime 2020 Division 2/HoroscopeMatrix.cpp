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

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

bool Verify(vector<int> f){
    int check = f[0];
    fr(l,0,f.size()-1){
        if (check != f[l])
            return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec2d(v,int,n,m,0);
        Input_Matrix(v,n,m);

        vector<vector<int>> dia;
        vector<bool> state;

        int x = 0, y = m-1;
        while(x!=n-1 || y!=0){
            int i = x, j = y;
            vector<int> d;
            while(i<n && j<m){
                d.push_back(v[i][j]);
                i++;
                j++;
            }
            dia.push_back(d);
            state.push_back(Verify(d));

            if (x==0 && y>0)
                y--;
            else
                x++;

            if (x==n-1 && y==0){
                dia.push_back({v[x][y]});
                state.push_back(true);
            }
        }

        int q;
        cin >> q;
        int i,j,val,r,c;
        while(q--){
            cin >> i >> j >> val;
            i--;
            j--;
            r = i + m - 1 - j;
            c = min(i,j);
            dia[r][c] = val;

            vector<int> f = dia[r];
            state[r] = Verify(f);

            bool vali = true;

            fr(i,0,state.size()-1){
                vali = vali && state[i];
            }

            if (vali)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }        
    }
}