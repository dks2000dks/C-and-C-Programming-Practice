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

int findMinInsertions(string s, int l, int r){
    if (l > r)
        return INT_MAX;
    if (l == r)
        return 0;

    if (l == r-1)
        return (s[l] == s[r]) ? 0 : 1;

    return (s[l] == s[r]) ? findMinInsertions(s,l+1,r-1) : (1+ min(findMinInsertions(s,l,r-1),findMinInsertions(s,l+1,r)));
}

int main(){
    string s;
    cin >> s;

    cout << findMinInsertions(s,0,s.length()-1) << endl;

    return 0;
}