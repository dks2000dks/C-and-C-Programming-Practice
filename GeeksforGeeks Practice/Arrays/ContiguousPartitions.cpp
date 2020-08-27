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

// O(nlogn)
int ComputeSlower(vector<int> &v, int n){
    
    vec1d(prefixArray,int,n,0);
    prefixArray[0] = v[0];
    vec1d(suffixArray,int,n,0);
    suffixArray[n-1] = v[n-1];

    fr(i,1,n-1){
        prefixArray[i] = prefixArray[i-1] + v[i];
    }

    int sum = prefixArray[n-1];
    if (sum % 3 != 0)
        return 0;
    
    for(int i=n-2;i>=0;i--){
        suffixArray[i] = suffixArray[i+1] + v[i];
    }

    vector<int> data;
    fr(i,0,n-1){
        if (suffixArray[i] == sum/3)
            data.push_back(i);
    }

    int count = 0;
    fr(i,0,n-1){
        if (prefixArray[i] == sum/3){
            int ind = upper_bound(data.begin(),data.end(),i+1) - data.begin();
            
            if (ind < data.size())
                count += data.size() - ind;
        }
    }

    return count;
}

// O(n)
int ComputeFaster(vector<int> &v, int n){
    vec1d(suffixArray,int,n,0);
    suffixArray[n-1] = v[n-1];
    
    for(int i=n-2;i>=0;i--){
        suffixArray[i] = suffixArray[i+1] + v[i];
    }

    int sum = suffixArray[0];
    if (sum % 3 != 0)
        return 0;

    fr(i,0,n-1){
        if (suffixArray[i] == sum/3)
            suffixArray[i] = 1;
        else
            suffixArray[i] = 0;
    }

    for(int i=n-2;i>=0;i--){
        suffixArray[i] += suffixArray[i+1];
    }

    int count = 0;
    int currsum = 0;
    fr(i,0,n-1){
        currsum += v[i];

        if (currsum == sum/3){
            count += suffixArray[i+2];
        }
    }

    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        cout << ComputeSlower(v,n) << endl;
    }
}