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

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        set<char> s = {'@', '#', '$', '%', '^', '&', '~', '*', '!'};

        map<char,int> mp;
        char c;

        fr(i,1,2*n){
            cin >> c;
            mp[c] = 1;
        }

        for(auto it=s.begin();it!=s.end();it++){
            if (mp.find(*it) != mp.end())
                cout << *it << " ";
        }
        cout << endl;

        for(auto it=s.begin();it!=s.end();it++){
            if (mp.find(*it) != mp.end())
                cout << *it << " ";
        }
        cout << endl;
    }
}