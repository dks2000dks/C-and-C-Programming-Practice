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

void Compute(string s, int k, string &max, int ind){
    if (k==0)
        return;

    int n = s.length();

    char maxm = s[ind];
    fr(j,ind+1,n-1){
        if (maxm < s[j])
            maxm = s[j];
    }

    if (maxm != s[ind])
        k--;

    fr(j,ind,n-1){
        if (s[j] == maxm){
            swap(s[j],s[ind]);

            if (s.compare(max) > 0)
                max = s;
                
            Compute(s,k,max,ind+1);

            swap(s[ind],s[j]);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        string s;

        cin >> k;
        cin >> s;

        string max = s;

        Compute(s,k,max,0);

        cout << max << endl;
    }
}