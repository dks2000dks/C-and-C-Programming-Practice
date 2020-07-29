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

void Process(vector<int> &v, int k){
    int n = v.size();
    int l;

    if (n%(k+1) == 0){
        l = n/(k+1);
    }

    else{
        l = (n/(k+1)) + 1; 
    }

    int mini=0;

    fr(i,0,l-1){
        mini += v[i];
    }

    int maxi = 0;
    fr(i,0,l-1){
        maxi += v[n-1-i];
    }

    cout << mini << " " << maxi << endl; 

}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        sort(v.begin(),v.end());

        Process(v,k);
    }
}