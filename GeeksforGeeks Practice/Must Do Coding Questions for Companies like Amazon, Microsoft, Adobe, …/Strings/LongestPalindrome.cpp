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

int CheckPalindrome(string s){
    string a = s;
    reverse(a.begin(),a.end());
    if (a == s)
        return 1;
    else
        return 0;    
}

string SubString(string s){
    int start = 0;
    int end = 0;
    int maxlen = 1;
    int n = s.length();

    fr(i,0,n-1){
        fr(j,i,n-1){
            string sb = s.substr(i,j-i+1);
            if (CheckPalindrome(sb)){
                if (sb.length() == maxlen){
                    if (i <= start){
                        start = i;
                        end = j;
                    }
                }

                else if (sb.length() > maxlen){
                    start = i;
                    end = j;
                    maxlen = sb.length();   
                }
            }
        }
    }

    return s.substr(start,end-start+1);
}

int main(){
    int T;
    cin >> T;

    while(T--){
        string s;
        cin >> s;

        if (CheckPalindrome(s)){
            cout << s << endl;
        }
        else
        {
            string o = SubString(s);
            cout << o << endl;
        }
        

    }
}