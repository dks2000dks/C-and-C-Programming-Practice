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

int Process(vector<int> &v, int k){
    sort(v.begin(),v.end());
    int n = v.size();

    int mincount = INT_MAX;
    int count = 0;

    fr(i,0,n-1){
        if (v[i] <= k){
            k = k-v[i];
            count++;
        }
    }

    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        cout << Process(v,k) << endl;
    }
}