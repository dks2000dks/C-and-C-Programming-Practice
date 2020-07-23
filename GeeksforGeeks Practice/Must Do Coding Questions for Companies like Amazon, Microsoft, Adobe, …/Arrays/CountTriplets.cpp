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
	for (int i = 0; i < size; i++) cin >> array[i];
}

int CountTriplets(vector<int> &v){
    int count = 0;
    int n = v.size();

    int maxi = v[n-1];

    vec1d(Hash,int,maxi+1,0);
    fr(i,0,n-1){
        Hash[v[i]] = 1; 
    }

    fr(i,0,n-3){
        fr(j,i+1,n-2){
            if (v[i]+v[j] <= v[n-1])
                count += Hash[v[i]+v[j]];
        }
    }

    return (count != 0) ? count : -1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        sort(v.begin(),v.end());
        cout << CountTriplets(v) << endl;
    }
}