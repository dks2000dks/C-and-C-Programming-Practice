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

int Compute(string s){
    int n = s.length();

    vector<int> lastIndex(256, -1);

    int start = 0;
    int maxlen = 0;

    fr(i,0,n-1){
        start = max(start, lastIndex[s[i]] + 1);
        maxlen = max(maxlen,i-start+1);
        lastIndex[s[i]] = i;
    }
    return maxlen;    
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        cout << Compute(s) << endl;
    }
}