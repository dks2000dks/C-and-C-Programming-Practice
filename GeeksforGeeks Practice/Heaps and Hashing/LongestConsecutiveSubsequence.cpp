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

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int Compute(vector<int>&v, int n){
    sort(v.begin(),v.end());
    //Print_Vector(v,n);

    int maxlen = 1;
    int count = 1;
    int verify = v[0];

    fr(i,1,n-1){
        if (v[i] == verify+1){
            count++;
            verify++;
        }
        else if (v[i] == verify){
            continue;
        }
        else{
            maxlen = max(count,maxlen);
            count = 1;
            verify = v[i];
        }
    }
    maxlen = max(maxlen,count);

    return maxlen;
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