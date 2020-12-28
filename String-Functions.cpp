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

vector<int> LPS(string p){
    int m = p.length();

    int l = 0;
    vector<int> lps(m,0);

    int i = 1;
    while(i<m){
        if (p[i] == p[l]){
            l++;
            lps[i] = l;
            i++;
        }
        else{
            if (l!=0)
                l = lps[l-1];
            else{
                lps[i] = 0;
                i++;
            }   
        }
    }
    return lps;
}

vector<int> KMP(string s, string p){
    vector<int> lps = LPS(p);
    int n = s.length();
    int m = p.length();
    vector<int> o;

    int i=0,j=0;
    while(i<n){
        if (p[j] == s[i]){
            j++;
            i++;
        }

        if (j == m){
            o.push_back(i-j);
            j = lps[j-1];
        }

        else if (i<n && p[j] != s[i]){
            if (j!=0)
                j = lps[j-1];
            else
                i++;            
        }
    }
    return o;
}
