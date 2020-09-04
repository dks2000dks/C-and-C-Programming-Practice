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

int Compute(vector<int> &v, int n){
    vec1d(left,int,n,0);
    vec1d(right,int,n,0);

    left[0] = 1;
    right[n-1] = 1;

    fr(i,1,n-1){
        if (v[i-1] < v[i])
            left[i] = left[i-1] + 1;
        else
            left[i] = 1;
    }

    for(int i=n-2;i>=0;i--){
        if (v[i+1] < v[i])
            right[i] = right[i+1] + 1;
        else
            right[i] = 1;
    }

    int count = 0;

    fr(i,0,n-1){
        count += max(left[i],right[i]);
    }

    return count;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n) << endl;

    }
}