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

int LBS(vector<int> &v){
    int n = v.size();

    vector<int> lis = v;
    vector<int> lds = v;

    fr(i,1,n-1){
        fr(j,0,i-1){
            if (v[j] < v[i])
                lis[i] = max(lis[j] + v[i], lis[i]);
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1;j > i; j--){
            if (v[j] < v[i])
                lds[i] = max(lds[j] + v[i], lds[i]);
        }
    }


    int m = INT_MIN;
    fr(i,0,n-1){
        m = max(m,lis[i]+lds[i]-v[i]);
    }
    return m;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << LBS(v) << endl; 
    }
}