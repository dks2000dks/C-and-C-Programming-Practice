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

int isvalid(int x, int y, int r, int c){
    return (x>=0 && x<r && y>=0 && y<c);
}

int Explore(int n, int m){
    vector<int> xMove = {2, 1, -1, -2, -2, -1, 1, 2};
	vector<int> yMove = {1, 2, 2, 1, -1, -2, -2, -1};

    int count = 0;

    fr(i,0,n-1){
        fr(j,0,m-1){
            int x = i;
            int y = j;
            int valid = n*m - 1;

            fr(k,0,7){
                if (isvalid(x+xMove[k],y+yMove[k], n, m))
                    valid--;
            }
            count += valid;
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        cout << Explore(n,m) << endl;
    }
}