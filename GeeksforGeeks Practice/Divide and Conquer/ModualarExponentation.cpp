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

int Compute(int a, int b, int c){
    a = a%c;

    if (a==0)
        return 0;
    if (a==1)
        return 1;

    int result = 1;
    while(b>0){
        if (b%2 == 1){
            result = (result*a)%c;
        }
        b = b/2;
        a = (a*a)%c;
    }
    return result;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;

        cout << Compute(a,b,c) << endl;
    }
}