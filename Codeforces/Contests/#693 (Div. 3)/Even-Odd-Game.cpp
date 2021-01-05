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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> even,odd;
        int num;

        fr(i,0,n-1){
            cin >> num;
            if (num%2 == 0)
                even.push_back(num);
            else
                odd.push_back(num);
        }

        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());

        bool p = true;
        int es,os;

        int a = 0,b = 0;

        while(even.size() + odd.size() > 0){
            es = accumulate(even.begin(),even.end(),0);
            os = accumulate(odd.begin(),odd.end(),0);

            if (es > os){
                if (p)
                    a += even.back();
                even.pop_back();
            }
            else{
                if (!p)
                    b += odd.back();
                odd.pop_back();
            }

            p = !p;
        }

        if (a > b)
            cout << "Alice" << endl;
        else if (a == b)
            cout << "Tie" << endl;
        else
            cout << "Bob" << endl;
    }
}