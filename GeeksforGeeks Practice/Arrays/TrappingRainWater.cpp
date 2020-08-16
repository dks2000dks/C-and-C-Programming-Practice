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

int CalculateStorage(vector<int> &v, int n){
    int m = max_element(v.begin(),v.end()) - v.begin();
    vector<int> maxcap(n,0);
    maxcap[m] = v[m];

    for(int i=0;i<m;i++){
        if (i==0)
            maxcap[i] = v[i];
        else{
            maxcap[i] = max(v[i],maxcap[i-1]);
        }
    }

    for(int i=n-1;i>m;i--){
        if (i==n-1)
            maxcap[i] = v[i];
        else{
            maxcap[i] = max(v[i],maxcap[i+1]);
        }
    }

    int cap = 0;

    fr(i,0,n-1){
        cap += (maxcap[i] - v[i]);
    }
    return cap;
}
int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << CalculateStorage(v,n) << endl;
    }
}