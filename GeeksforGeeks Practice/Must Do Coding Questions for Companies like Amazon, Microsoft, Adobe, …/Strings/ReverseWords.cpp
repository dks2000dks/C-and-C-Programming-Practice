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

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;
        stack<string> st;
        string sp = "";
        fr(i,0,s.length()-1){
            if (s[i] == '.' ){
                st.push(sp);
                sp = "";
            }

            else{
                sp += s[i];
            }
        }
        st.push(sp);

        while(!st.empty()){
            cout << st.top();
            st.pop();
            if (!st.empty())
                cout << ".";
        }
        cout << endl;
    }
}