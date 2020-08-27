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

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int Compute(vector<int> &v, int k){
    int n = v.size();
    if (n < 3)
        return 0;
    
    sort(v.begin(),v.end());

    int i=0;
    int sum,diff,nearsum,minDiff = INT_MAX;

    while(i < n-2){
        int l = i+1;
        int r = n-1;

        while(l < r){
            sum = v[i] + v[l] + v[r];
            diff = abs(sum-k);

            if (sum == k)
                return k;

            if (diff < minDiff){
                minDiff = diff;
                nearsum = sum;
            }

            if (sum < k)
                l++;
            
            else
                r--;
        }
        i++;
    }
    return nearsum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        if (Compute(v,k) == k)
            cout << 1 << endl;
        else{
            cout << 0 << endl;
        }
    }
}