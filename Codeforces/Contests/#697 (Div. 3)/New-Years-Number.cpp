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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int b = n%2020;
        int a = n/2020 - b;

        if ((a+b)*2020 + b == n && a>=0 && b>=0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}