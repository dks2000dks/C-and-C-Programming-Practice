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

int Compute(vector<int> &v, int n){
    int start = 0;
    int end = 0;
    
    vector<pair<int,int>> o;
    fr(i,0,n-2){
        if (v[i] < v[i+1]){
            end++;
        }

        else{
            if (start < end)
                o.push_back(make_pair(start,end));

            start = i+1;
            end = i+1;
        }
    }

    if (start < end)
        o.push_back(make_pair(start,end));

    if (o.size() == 0)
        cout << "No Profit" << endl;

    else{
        fr(i,0,o.size()-1)
            cout << "(" << o[i].first << " " << o[i].second << ")" << " ";
        cout << endl;
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        Compute(v,n);
    }
}