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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))
#define CHARS 26

string Removed(string s)
{
    char prev = s[0];
    int n = s.length();
    string output = "";

    deque<char> q;
    q.push_back(s[0]);
    int t = 1;

    fr(i, 1, n-1){
        if (s[i-1] != s[i]){
            if (t != 1){
                while (!q.empty() && t > 0){
                    //cout << "Removed: " << q.back() << endl;
                    q.pop_back();
                    t--;
                }
            }
            q.push_back(s[i]);
            t = 1;
        }

        else{
            q.push_back(s[i]);
            t += 1;
        }
        //cout << s[i] << " " << t << endl;
    }

    if (t != 1){
        while (!q.empty() && t > 0){
            //cout << "Removed: " << q.back() << endl;
            q.pop_back();
            t--;
        }
    }

    while (!q.empty()){
        output += q.front();
        q.pop_front();
    }

    return output;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string prev =  Removed(s);
        string cur;
        int p = 1;

        while(p){
            cur = Removed(prev);
            if (cur == prev){
                p=0;
            }
            else{
                p = 1;
                prev = cur;
            }
        }

        cout << cur << endl;
    }
}