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

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        
        vec1d(v,int,n*n,0);

        for(int i=n-1;i>=0;i--){
            fr(j,0,n-1){
                cin >> v[i + j*n];
            }
        }

        fr(i,0,n*n - 1) cout << v[i] << " ";
        cout << endl;
    }
}