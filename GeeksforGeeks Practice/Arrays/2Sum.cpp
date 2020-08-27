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

bool isPairPresent(vector<int> v, int target){
    int n = v.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++){
        int temp = target - v[i];
        if (s.find(temp) != s.end())
            return true;

        s.insert(v[i]);
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        if (isPairPresent(v,k))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}