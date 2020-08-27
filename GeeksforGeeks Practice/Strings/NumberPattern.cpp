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
    /*
    int in = 0;
    int de = 0;
    int n = s.length();
    string output = "";

    fr(i,0,n-1){
        if (s[i] == 'I')
            in++;
        else
            de++;
    }

    int l = 1;
    int r = n+1;
    int i = 0;

    while(output.length() < n+1){
        if (s[i] == 'I'){
            output += to_string(l);
            l++;
            i++;
        }
        else{
            output += to_string(r);
            r--;
            i++;
        }
    }

    return output;
    */

    vector<int> res;
    int v = 1;
    int prev_i = 0, start = 0;
    for (int i = 0; i < s.size(); ++i) {
        prev_i = i;
        while (i < s.size() && s[i] == 'D') ++i;
        int cnt = i - prev_i + 1;
        for (int j = 0; j < cnt; ++j) res.push_back(start+cnt-j);
        start += cnt;
    }
    if (s.back() == 'I') res.push_back(start+1);

    string output = "";

    fr(i,0,res.size()-1){
        output += to_string(res[i]);
    }

    return output;
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