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

int PossiblePaths(int x, int y){
    if (x==1 || y==1)
        return 1;
    return PossiblePaths(x-1,y) + PossiblePaths(x,y-1);
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int x,y;
        cin >> x >> y;

        cout << PossiblePaths(x,y) << endl;
    }
}