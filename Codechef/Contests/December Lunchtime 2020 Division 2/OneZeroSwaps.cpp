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

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s,p;
        cin >> s >> p;
        string a = s;
        string b = p;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if (a!=b)
            cout << "No" << endl;
        else{
            bool d = true;
            fr(i,0,n-1){
                if (p[i] == s[i])
                    continue;
                else{
                    if (s[i] == '0'){
                        cout << "No" << endl;
                        d = false;
                        break;
                    }
                    else{
                        int j = i+1;
                        while(s[j] != '0')
                            j++;
                        swap(s[i],s[j]);
                    }
                }
            }
            if (d)
                cout << "Yes" << endl;
        }
    }
}