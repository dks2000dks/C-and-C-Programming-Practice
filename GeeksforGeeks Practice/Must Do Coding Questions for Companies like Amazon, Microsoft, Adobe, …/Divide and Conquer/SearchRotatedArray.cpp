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

int Search(vector<int> &v, int l, int r, int k){
    int n = r-l+1;

    if (n==1){
        if (v[l] == k)
            return l;
        else
            return -1;
    }
    
    else{
        int mid = (l+r)/2;
        int a = Search(v,l,mid,k);
        int b = Search(v,mid+1,r,k);

        if (a == -1 && b == -1)
            return -1;
        else if (a==-1 && b!=-1)
            return b;
        else if (a!=-1 && b==-1)
            return a;
        }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];
        int k;
        cin >> k;
        cout << Search(v,0,n-1,k) << endl;
    }
}