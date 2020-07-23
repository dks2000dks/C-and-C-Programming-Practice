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

int Output_Matrix(vector<vector<int>> &mat, int n, int m){
	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			cout << mat[i][j] << " ";
		}
	}
    cout << endl;
}

int isvalid(int x, int y, int r, int c){
    return (x>=0 && x<r && y>=0 && y<c);
}

void Process(vector< vector<int>> &v, int r, int c, int x, int y, int k){

    int target = v[x][y];
    v[x][y] = k;

    if (isvalid(x-1,y,r,c) && v[x-1][y] == target){
        Process(v,r,c,x-1,y,k);
    }

    if (isvalid(x+1,y,r,c) && v[x+1][y] == target){
        Process(v,r,c,x+1,y,k);
    }

    if (isvalid(x,y-1,r,c) && v[x][y-1] == target){
        Process(v,r,c,x,y-1,k);
    }
        

    if (isvalid(x,y+1,r,c) && v[x][y+1] == target){
        Process(v,r,c,x,y+1,k);
    }

    return ;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int r,c;
        cin >> r >> c;
        vec2d(v,int,r,c,0);
        Input_Matrix(v,r,c);
        //Output_Matrix(v,r,c);

        int x,y,k;
        cin >> x >> y >> k;

        Process(v,r,c,x,y,k);
        Output_Matrix(v,r,c);
    }
}