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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v1,ll,n,0);
        vec1d(v2,ll,n,0);
        Input_Vector(v1,n);
        Input_Vector(v2,n);

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),greater<ll>());

        ll sum=0;
        fr(i,0,n-1){
            sum += v1[i] * v2[i];
        }
        cout << sum << endl;
    }
}