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

int PairsDifference(vector<int> &v, int k){
    int n = v.size();

    sort(v.begin(),v.end());

    int output =0;

    for(int i=n-1; i>=0; i--){
        if (v[i] - v[i-1] < k && i>=1){
            output += v[i] + v[i-1];
            i--;
        }
    }
    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        int k;
        cin >> k;

        cout << PairsDifference(v,k) << endl;
    }
}