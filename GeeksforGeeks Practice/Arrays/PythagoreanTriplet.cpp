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

int Compute(vector<int> &v){
    int n = v.size();
    fr(i,0,n-1)
        v[i] *= v[i];

    sort(v.begin(),v.end());

     for (int i = n - 1; i >= 2; i--) { 
        int l = 0;
        int r = i - 1;
        while (l < r) { 
            if (v[l] + v[r] == v[i]) 
                return true; 
  
            (v[l] + v[r] < v[i]) ? l++ : r--; 
        } 
    } 

    return false;
    
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        
        if (Compute(v))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}