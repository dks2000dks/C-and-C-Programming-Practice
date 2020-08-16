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

string URL(long int n){
    string All = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string url = "";

    while(n){
        url = All[n%62] + url;
        n = n/62;
    }
    return url;
}

int Encoded(string url){
    long int id = 0;
    int n = url.length();

    fr(i,0,n-1){
        if ('a' <= url[i] && url[i] <= 'z') 
            id = id*62 + url[i] - 'a'; 
        if ('A' <= url[i] && url[i] <= 'Z') 
            id = id*62 + url[i] - 'A' + 26; 
        if ('0' <= url[i] && url[i] <= '9') 
            id = id*62 + url[i] - '0' + 52;
    }

    return id;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        long int n;
        cin >> n;
        string url = URL(n);
        cout << url << endl;
        cout << Encoded(url) << endl;
    }
}