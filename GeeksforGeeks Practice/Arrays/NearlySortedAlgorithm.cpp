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
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        sort(v.begin(),v.end());

        fr(i,0,n-1) cout << v[i] << " ";
        cout << endl;
    }
}