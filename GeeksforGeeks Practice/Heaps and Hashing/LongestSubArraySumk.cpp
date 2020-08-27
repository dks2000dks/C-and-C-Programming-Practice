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
    unordered_map<int,int> mp;

    int sum = 0;
    int maxlen = 0;

    fr(i,0,n-1){
        sum += v[i];  

        if (sum == k)
            maxlen = i+1; 

        if (mp.find(sum) == mp.end())
            mp[sum] = i; 

        if (mp.find(sum-k) != mp.end()){
            maxlen = max(maxlen,i - mp[sum-k]);
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