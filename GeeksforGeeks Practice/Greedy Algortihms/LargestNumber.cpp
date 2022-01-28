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

int Process(int n, int s){
    if (s==0){
        if (n==1)
            return 0;
        else
            return -1;
    }

    else if (s > 9*n){
        return -1;
    }

    else{
        string num;
        
        fr(i,0,n-1){
            if (s>=9){
                s = s-9;
                num += "9";
            }

            else{
                num += to_string(s);
                s=0;
            }
        }

        return stoi(num);
    }

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;

        cout << Process(n,s) << endl;
    }
}