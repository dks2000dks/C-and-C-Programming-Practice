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
#define fr(i, a, b) for (ll i=a; i<=b; i++)
#define br(i, a, b) for (ll i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> a;
        ll s,v;

        fr(i,0,n-1){
            cin >> s;
            fr(j,0,s-1){
                cin >> v;
                a.push_back(v);
            }
        }

        sort(a.begin(),a.end());

        ll neg = 0, pos = 0;

        fr(i,0,a.size()-1){
            if (a[i] < 0)
                neg++;
            else
                pos++;
        }

        cout << pos * neg << endl;
    }
}