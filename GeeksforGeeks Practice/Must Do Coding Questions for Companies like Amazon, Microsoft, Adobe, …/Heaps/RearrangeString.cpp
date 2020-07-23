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

struct Key{
    int freq;
    char c;

    bool operator<(const Key &k) const{
        return freq < k.freq;
    }
};

int Compute(string s){
    string output="";

    int n = s.length();

    vec1d(Freqs,int,26,0);

    fr(i,0,n-1) Freqs[s[i]-'a']++;

    priority_queue<Key> pq;

    for (char c='a'; c<='z'; c++){
        if (Freqs[c-'a'] > 0){
            pq.push(Key{Freqs[c-'a'],c});
        }
    }

    Key prevChar {-1, '#'};

    while(!pq.empty()){
        Key k = pq.top();
        pq.pop();
        output += k.c;

        if (prevChar.freq > 0)
            pq.push(prevChar);

        (k.freq)--;
        prevChar = k;
    }

    if (output.length() == s.length())
        return 1;
    else
        return 0;
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