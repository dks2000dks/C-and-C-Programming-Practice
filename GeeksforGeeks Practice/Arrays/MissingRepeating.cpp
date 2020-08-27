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
    int total = n*(n+1)/2;
    vector<int> o(2,0);

    fr(i,0,n-1){
        if (v[abs(v[i]) - 1] > 0)
            v[abs(v[i]) - 1] = -v[abs(v[i]) - 1];
        else{
            o[0] = abs(v[i]);
        }
    }

    fr(i,0,n-1){
        if (v[i] > 0)
            o[1] = i+1;
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
        Print_Vector(o,2);
    }
}

