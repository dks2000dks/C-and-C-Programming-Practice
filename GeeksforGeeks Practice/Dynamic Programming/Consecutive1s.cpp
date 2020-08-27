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
#define p 1000000007

int Compute(int n){
    int a[n], b[n]; 
    a[0] = b[0] = 1; 

    for (int i = 1; i < n; i++) { 
        a[i] = (a[i-1] + b[i-1])%p; 
        b[i] = (a[i-1])%p; 
    }
    return (a[n-1] + b[n-1])%p; 
}


int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        cout << Compute(n) << endl;
    }
}