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

int Process (vector<int> &v, int k){
    int n = v.size();

    if (n==1)
        return 0;
    
    int diff = v[n-1] - v[0];

    int mini = v[0] + k;
    int maxi = v[n-1] - k;

    if (maxi < mini)
        swap(mini,maxi);

    v[0] = mini;
    v[n-1] = maxi;

    fr(i,1,n-2){
        int s = v[i] - k;
        int a = v[i] + k;

        if (s >= mini || a <= maxi){
            if (s >= mini && a>maxi){
                v[i] = s;
            }

            else{
                v[i] = a;
            }
            continue;
        }

        if (maxi-s <= a-mini){
            mini = s;
            v[i] = s;
        }

        else{
            maxi = a;
            v[i] = a;
        }
    }

    return min(diff,maxi-mini);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        int n;
        cin >> n;

        vec1d(v,int, n, 0);
        fr(i,0,n-1){
            cin >> v[i];
        }

        sort(v.begin(),v.end());

        cout << Process(v,k) << endl;

    }
}