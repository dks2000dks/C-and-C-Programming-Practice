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

bool isValid(string s) {
    if (s.size() > 1 && s[0]  ==  '0')
        return false;
    if (stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}

vector<string> genIp(string &s) {
    vector<string> ans;
    if (s.size() > 12 || s.size() < 4)
        return ans;

    for (int i = 1; i < 4; i++) {
        string first  =  s.substr(0, i);
        if (!isValid(first))
            continue;
        for (int j = 1; i + j < s.size() && j < 4; j++) {
            string second  =  s.substr(i, j);
            if (!isValid(second))
                continue;
            for (int k = 1; i + j + k < s.size() && k < 4; k++) {
                string third = s.substr(i + j, k);
                string fourth = s.substr(i + j + k);
                if (isValid(third) && isValid(fourth)) {
                    string current  =  first + "." + second + "." + third + "." + fourth;
                    ans.push_back(current);
                }
            }
        }
    }
    return ans;
}

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