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

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int Compute(vector<int> &v, int n, int k){
    vec1d(mod,int,n,0);
    int sum = 0;
    fr(i,0,n-1){
        sum += v[i];
        mod[i] = ((sum%k)+k)%k;
    }

    unordered_map<int,int> mp;
    int maxlen = 0;

    fr(i,0,n-1){ 

        if (mod[i] == 0)
            maxlen = i+1; 

        else if (mp.find(mod[i]) == mp.end())
            mp[mod[i]] = i; 

        else{
            maxlen = max(maxlen,i - mp[mod[i]]);
        }
    }
    return maxlen;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n,k) << endl;
    }
}