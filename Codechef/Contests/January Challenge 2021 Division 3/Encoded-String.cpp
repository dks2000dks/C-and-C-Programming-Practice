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

string Convert(vector<string> v){
    string o = "";
    fr(i,0,v.size()-1){
        int n = 0;
        fr(j,0,3){
            n += pow(2,3-j)*(v[i][j] - '0');
        }
        o += ((char)(n + (int)'a'));
    }
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        n = n/4;
        vec1d(v,string,n,"0");
        fr(i,0,n-1){
            v[i] = s.substr(4*i,4);
        }
        cout << Convert(v) << endl;
    }
}