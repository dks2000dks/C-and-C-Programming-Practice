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

int Painters(vector<int> v, int n, int maxlen){
    int p = 1;
    int t = 0;
    fr(i,0,n-1){
        t+=v[i];
        if (t > maxlen){
            p++;
            t = v[i];
        }
    }
    return p;
}

int Compute(vector<int> v, int n, int k){
    int l = *max_element(v.begin(),v.end());
    int r = accumulate(v.begin(),v.end(),0);

    while(l<r){
        int m = (l+r)/2;
        int p = Painters(v,n,m);

        if (p<=k)
            r = m;
        else
            l = m+1;
    }
    return l;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> k >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n,k) << endl;
    }
}