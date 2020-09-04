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

void Input_Vector(vector<ll> &array, ll size){
	for (ll i = 0; i < size; i++){
		cin >> array[i];
	}
}

bool Painters(vector<ll> v, ll n, ll m, ll maxlen){
    ll p = 1;
    ll sum = 0;

    fr(i,0,n-1){
        if (v[i] > maxlen)
            return false;

        if (sum + v[i] > maxlen){
            p++;
            sum = v[i];

            if (p > m)
                return false;
        }

        else{
            sum += v[i];
        }
    }
    return true;
}

int Compute(vector<ll> v, ll n, ll m){
    if (n<m)
        return -1;

    ll l = 0;
    ll r = 0;
    r = accumulate(v.begin(),v.end(),r);
    ll maxpages = INT_MAX;

    while(l<=r){
        ll mid = (l+r)/2;

        if (Painters(v,n,m,mid)){
            r = mid-1;
            maxpages = min(maxpages,mid);
        }
        else{
            l = mid+1;
        }
    }
    return maxpages;
}

int main(){
    ll T;
    cin >> T;

    while(T--){
        ll n,m;
        cin >> n;
        vec1d(v,ll,n,0);
        Input_Vector(v,n);
        cin >> m;
        cout << Compute(v,n,m) << endl;
    }
}