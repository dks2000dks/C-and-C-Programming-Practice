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

void Input_Vector(vector<ll> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

ll Compute(vector<ll> &v, int n){
    sort(v.begin(),v.end());
    ll o = 2*(v[n-1] - v[0]);
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,ll,n,0);
        Input_Vector(v,n);
        printf("%lld\n",Compute(v,n));
    }
}