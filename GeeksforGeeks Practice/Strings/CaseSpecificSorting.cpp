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

string Compute(string s){
    
    int n = s.length();
    list<char> l;
    list<char> u;

    fr(i,0,n-1){
        if (islower(s[i])){
            l.push_back(s[i]);
        }
        else{
            u.push_back(s[i]);
        }
    }

    l.sort();
    u.sort();
    string o = "";

    fr(i,0,n-1){
        if (islower(s[i])){
            o += l.front();
            l.pop_front();
        }
        else{
            o += u.front();
            u.pop_front();
        }
    }
    return o;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        string s;
        cin >> s;

        cout << Compute(s) << endl;
    }
}