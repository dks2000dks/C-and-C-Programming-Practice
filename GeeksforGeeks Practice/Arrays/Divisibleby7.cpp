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

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int Compute(vector<int> &v1, vector<int> &v2, vector<int> &v3, int l, int m, int n){

    vector<int> mod1(7,0);
    vector<int> mod2(7,0);
    vector<int> mod3(7,0);

    fr(i,0,l-1)
        mod1[(v1[i])%7]++;

    fr(i,0,m-1)
        mod2[(v2[i])%7]++;

    fr(i,0,n-1)
        mod3[(v3[i])%7]++;

    int count = 0;

    fr(i,0,6){
        fr(j,0,6){
            fr(k,0,6){
                if ((i+j+k)%7 == 0)
                    count += (mod1[i] * mod2[j] * mod3[k]);
            }
        }
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l,m,n;
        cin >> l >> m >> n;
        vec1d(v1,int,l,0);
        vec1d(v2,int,m,0);
        vec1d(v3,int,n,0);

        Input_Vector(v1,l);
        Input_Vector(v2,m);
        Input_Vector(v3,n); 

        cout << Compute(v1,v2,v3,l,m,n) << endl;
    }
}