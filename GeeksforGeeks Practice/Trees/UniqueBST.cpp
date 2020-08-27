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

int nCr(int n,int r){
    int output = 1;
    if (n - r < r) 
        r = n - r; 
  
    for(int i=n-r+1;i<=n;i++){
        output = output*(i)/(i-n+r);
    }
    return output;
}

int Compute(int n){
    return (nCr(2*n+1, n))/(2*n + 1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << Compute(n) << endl;
    }
}