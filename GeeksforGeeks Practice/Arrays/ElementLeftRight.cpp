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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}  

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	} 
	cout << endl;
}

int Compute(vector<int> &v){
    int n = v.size();

    vec1d(Prefix,int,n,0);
    vec1d(Suffix,int,n,0);

    fr(i,0,n-1){
        if (i==0)
            Prefix[i] = v[i];
        else{
            Prefix[i] = max(v[i],Prefix[i-1]);
        }
    }

    br(i,n-1,0){
        if (i==n-1)
            Suffix[i] = v[i];
        else{
            Suffix[i] = min(Suffix[i+1], v[i]);
        }
    }

    Print_Vector(Prefix,n);
    Print_Vector(Suffix,n);

    int Index = -1;
    fr(i,1,n-2){
        if (v[i] > Prefix[i-1] && v[i] < Suffix[i+1]){
            Index = i;
            break;
        }
    }
    if (Index == -1)
        return Index;
    return v[Index];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v) << endl;
    }
}