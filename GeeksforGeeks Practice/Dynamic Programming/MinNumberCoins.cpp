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

void Compute(int n){
    vector<int> den = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int m = den.size();

    while(n>0){
        for(int i=m-1;i>=0;i--){
            if (n-den[i] >= 0){
                cout << den[i] << " ";
                n -= den[i];
                i=-1;
            }
        }
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        Compute(n);
    }
}