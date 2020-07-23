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

int Compare(char a, char b){
    if (a == '(' and b == ')')
        return 1;
    else if (a == '[' and b == ']')
        return 1;
    else if (a == '{' and b == '}')
        return 1;
    else
        return 0;
}

int Check(){
    string s;
    cin >> s;

    stack<char> st;

    fr(i,0,s.length()-1){
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else{
            if (!st.empty()){

                char a = st.top();
                char b = s[i];

                if (Compare(a,b))
                    st.pop();
                else
                    return 0;
            }

            else{
                return 0;
            }
        }
    }

    if (st.empty())
        return 1;
    else
        return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int r = Check();

        if (r == 1)
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
}