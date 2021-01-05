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
        int w,h,n;
        cin >> w >> h >> n;

        int count = 1;

        while(w%2==0 || h%2==0){
            if (w%2 == 0){
                w = w/2;
                count = count*2;
            }
            else{
                h = h/2;
                count = count*2;
            }
        }

        if (count >= n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}