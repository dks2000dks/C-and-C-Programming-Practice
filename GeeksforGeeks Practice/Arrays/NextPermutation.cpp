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
    int i,j;

    for(i=n-2;i>=0;i--){
        if (v[i] < v[i+1])
            break;
    }

    if (i==-1){
        reverse(v.begin(),v.end());
        return v;
    }

    for(j = n-1; j>i;j--){
        if (v[j] > v[i])
            break;
    }

    swap(v[j],v[i]);

    reverse(v.begin()+i+1, v.end());

    return v;
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