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

string PreProcess(string s){
    string o = "";

    fr(i,0,s.length()-1){
        if (isalpha(s[i]) != 0){
            o += tolower(s[i]);
        }
        else if (isdigit(s[i])){
            o += s[i];
        }
    }
    return o;
}

string isPalindrome(string s){
    string o = s;
    reverse(o.begin(),o.end());

    if (s == o)
        return "YES";
    else
        return "NO";
}

int main(){
   int t;
   cin >> t;
   while(t--){
       string s;
       getline(cin,s);
       s = PreProcess(s);
       cout << isPalindrome(s) << endl;
   }
}