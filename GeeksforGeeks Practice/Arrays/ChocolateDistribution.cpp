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

void Input_Vector(vector<ll> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

ll Compute(vector<ll> &v, int m){
    sort(v.begin(),v.end());
    int n = v.size();

    ll mindiff=INT_MAX;

    fr(i,0,n-m){
        mindiff = min(mindiff,v[i+m-1]-v[i]);
    }
    return mindiff;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n;
        vec1d(v,ll,n,0);
        Input_Vector(v,n);
        cin >> m;

        cout << Compute(v,m) << endl;
    }
}