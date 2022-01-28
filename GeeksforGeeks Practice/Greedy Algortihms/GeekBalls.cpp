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

ll Process(vector<int> &v1, vector<int> &v2){
    int n = v1.size();
    int m = v2.size();

    int i=0,j=0;
    vector<int> common;
    while(i<n && j<m){
        if (v1[i] > v2[j])
            j++;
        else if (v1[i] < v2[j])
            i++;
        else{
            common.push_back(v1[i]);
            i++;
            j++;
        }
    }

    int k=0;
    ll s=0,p=0;
    i=0,j=0;
    ll balls = 0;

    while(i<n && j<m){
        int ua = upper_bound(v1.begin(),v1.end(),common[k]) - v1.begin();
        int ub = upper_bound(v2.begin(),v2.end(),common[k]) - v2.begin();

        while(i!=ua && i<=n){
            s+=v1[i];
            i++;
        }

        while(j!=ub && j<=m){
            p+=v2[j];
            j++;
        }
        balls += max(s,p);
        s=0,p=0,k++; 
    }
    
    return balls-INT_MAX;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec1d(v1,int,n+1,0);
        vec1d(v2,int,m+1,0);
        Input_Vector(v1,n);
        Input_Vector(v2,m);
        v1[n] = INT_MAX;
        v2[m] = INT_MAX;

        cout << Process(v1,v2) << endl;

    }
}