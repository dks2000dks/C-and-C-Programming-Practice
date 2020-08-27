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
    int i = 0;
    int j = 0;
    int count = 0;

    int sum = 0;
    while(j < n){
        sum += v[j];
        
        while(sum >= k && i<=j){
            sum -= v[i];
            i++;
        }

        if (i > j){
            j++;
            continue;
        }

        count += (j-i+1);
        j++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << Compute(v,n,k)<< endl;
    }
}