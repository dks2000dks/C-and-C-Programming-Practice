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

vector<string> genIp(string &s);

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        vector<string> str = genIp(s);
        sort(str.begin(), str.end());
        for (auto &u : str) {
            cout << u << "\n";
        }
    }
}

int isvalid(string s){
    string p="";

    for(int i=0;i<=s.length();i++){
        if (s[i] == '.' || i==s.length()){
            if (p[0] == '0' && p.length() > 1)
                return 0;

            if (stoi(p) > 255)
                return 0;

            p = "";
        }

        else{
            p += s[i];
        }
    }
    return 1;
}

vector<string> genIp(string &s) {
    int n = s.length();
    vector<string>output;

    // Max IPv4-IP Possible 255.255.255.255
    if (n>12)
        return output;

    for(int i=0; i<=n-4; i++){
        for(int j=i+1;j<=n-3;j++){
            for(int k=j+1;k<=n-2;k++){
                string ip = s;
                ip.insert(i+1,".");
                ip.insert(j+2,".");
                ip.insert(k+3,".");

                if (isvalid(ip))
                    output.push_back(ip);
            }
        }
    }
}