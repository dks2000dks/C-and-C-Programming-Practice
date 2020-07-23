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

ll MaxSubarraySum(vector<ll> &v){
    ll sum = v[0];
    ll s = v[0];
    int n = v.size();
    fr(i,1,n-1){
        s = max(s+v[i],v[i]);
        sum = max(s,sum);
    }

    return sum;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,ll,n,0);
        Input_Vector(v,n);

        cout << MaxSubarraySum(v) << endl;
    }
}