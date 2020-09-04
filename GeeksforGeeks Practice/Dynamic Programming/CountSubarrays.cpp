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

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int Compute(vector<int> &v, int n, int k){
    int s = 0;
    int i = 0;

    while(i < n){
        if (v[i] > k){
            i++;
            continue;
        }

        int count = 0;
        while(i < n && v[i] <= k){
            i++;
            count++;
        }

        s += (count*(count+1))/2;
    }

    return (n*(n+1))/2 - s;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << Compute(v,n,k) << endl;
    }
}