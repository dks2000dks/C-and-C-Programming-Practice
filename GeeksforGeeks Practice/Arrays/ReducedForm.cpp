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

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int> Compute(vector<int> &v, int n){
    vector<int> o = v;

    sort(o.begin(),o.end());

    map<int,int> mp;
    fr(i,0,n-1){
        mp[o[i]] = i;
    }

    fr(i,0,n-1){
        o[i] = mp[v[i]];
    }

    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vec1d(v,int,n,0);
        Input_Vector(v,n);

        vector<int> o = Compute(v,n);
        Print_Vector(o,n);
    }
}