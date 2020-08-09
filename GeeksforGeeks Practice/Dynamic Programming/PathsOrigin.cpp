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

ll Calculate(int m,int n){

    ll output = 1;
    
    int l = max(m,n);

    fr(i,l+1,m+n){
        output *= i;
        output /= (i-l);
    }

    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;

        cout << Calculate(m,n) << endl;
    }
}