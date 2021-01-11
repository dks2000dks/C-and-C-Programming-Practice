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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec1d(John,int,n,0);
        vec1d(Jack,int,m,0);
        Input_Vector(John,n);
        Input_Vector(Jack,m);
        sort(John.begin(),John.end());
        sort(Jack.begin(),Jack.end(),greater<int>());
        int i = 0;
        while(i<n && i<m && accumulate(John.begin(),John.end(),0) <= accumulate(Jack.begin(),Jack.end(),0)){
            swap(Jack[i],John[i]);
            i++;
        }
        if (accumulate(John.begin(),John.end(),0) > accumulate(Jack.begin(),Jack.end(),0))
            cout << i << endl;
        else
            cout << -1 << endl;
    }
}