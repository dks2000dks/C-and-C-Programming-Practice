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

vector<int> Compute(string s){
    int ones = 0;
    int n = s.length();
    vector<int> output;

    fr(i,0,n-1){
        if (s[i] == '1')
            ones++;
    }

    if (ones == n)
        return output;

    vector<int> v;
    fr(i,0,n-1){
        if (s[i] == '0')
            v.push_back(1);
        else{
            v.push_back(-1);
        }
    }

    //Kadane's Algotithm

    int maxsum = 0, sum = 0;
    int l=0,r=0,start=0;

    fr(i,0,n-1){
        sum += v[i];

        if (maxsum < sum){
            l = start;
            r = i;
            maxsum = sum;
        }

        if (sum < 0){
            sum = 0;
            start = i+1;
        }
    }

    // Indexes
    output.push_back(l);
    output.push_back(r);

    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        vector<int> o = Compute(s);

        if (o.size() > 0){
            fr(i,0,o.size()-1){
                cout << o[i] << " ";
            }
            cout << endl;
        }

        else{
            cout << endl;
        }
    }
}