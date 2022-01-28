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

void Permutations(string s, string soFar){
    if (s.length() == 0)
        cout << soFar << " ";

    else{
        fr(i,0,s.length()-1){
            string a = s;
            a.erase(a.begin()+i);
            Permutations(a, soFar+s[i]);
        }
    }
}

int main(){
    int T;
    cin >> T;

    while (T--){
        string s;
        cin >> s;
        sort(s.begin(),s.end());
        Permutations(s,"");
        cout << endl;
    }
}