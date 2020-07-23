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
#define CHARS 26

int MaxLen(string s){
    int n = s.length();
    
    int maxlen = 0;
    vec1d(lastIndex,int,CHARS,-1);

    int i=0;

    fr(j,0,n-1){
        i = max(i, lastIndex[s[j]-97]+1);

        maxlen = max(maxlen, j-i+1);
        lastIndex[s[j]-97] = j;
    }
    return maxlen;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << MaxLen(s) << endl;
    }
}