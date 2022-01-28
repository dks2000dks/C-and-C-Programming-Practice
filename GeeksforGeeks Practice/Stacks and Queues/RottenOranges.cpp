// https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

// Using BFS Approach

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

int isvalid(int x, int y, int r, int c){
    return (x<=r-1 && x>=0 && y<=c-1 && y>=0);
}

struct Position{
    int x;
    int y;
};

int Compute(vector<vector<int>> &v, int r, int c){
    queue<Position> q;

    fr(i,0,r-1){
        fr(j,0,c-1){
            if (v[i][j] == 2){
                Position p;
                p.x = i;
                p.y = j;
                q.push(p);
            }

        }
    }

    Position limiter;
    limiter.x = -1;
    limiter.y = -1;
    q.push(limiter);

    int time = 0;

    while (!q.empty()){
        Position p = q.front();
        q.pop();

        int i = p.x;
        int j = p.y;

        if (i == -1 && j == -1){
            if (q.size() != 0){
                time++;
                q.push(limiter);
            }
            continue;
        }

        if (isvalid(i-1,j,r,c) && v[i-1][j] == 1){
            Position p;
                p.x = i-1;
                p.y = j;
                v[i-1][j] = 2;
                q.push(p);
                //cout << i-1 << " " << j << endl;
        }

        if (isvalid(i+1,j,r,c) && v[i+1][j] == 1){
            Position p;
                p.x = i+1;
                p.y = j;
                v[i+1][j] = 2;
                q.push(p);
                //cout << i+1 << " " << j << endl;
        }

        if (isvalid(i,j-1,r,c) && v[i][j-1] == 1){
            Position p;
                p.x = i;
                p.y = j-1;
                v[i][j-1] = 2;
                q.push(p);
                //cout << i << " " << j-1 << endl;
        }

        if (isvalid(i,j+1,r,c) && v[i][j+1] == 1){
            Position p;
                p.x = i;
                p.y = j+1;
                v[i][j+1] = 2;
                q.push(p);
                //cout << i << " " << j+1 << endl;
        }
    }

    fr(i,0,r-1){
        fr(j,0,c-1){
            if (v[i][j] == 1){
                return -1;
            }

        }
    }

    return time;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        vec2d(v,int,r,c,0);
        Input_Matrix(v,r,c);

        int time = Compute(v,r,c);
        cout << time << endl;
    }
}