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
    long long  num = 0;

    int i=0;
    int len = s.size();
    
    while(i<len){
        num = num*10+(s[i]-'0');
        i++;
    }

    if (num == 1){
        return 0;
    }

    int p = num-1;

    if ((num & p) == 0)
        return 1;
    else{
        return 0;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        cout << Compute(s) << endl;
    }
}