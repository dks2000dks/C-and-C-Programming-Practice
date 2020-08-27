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
    stack<int> s;

    int maxArea = 0;
    int tp;
    int area_with_top;

    int i=0;
    while(i<n){

        if (s.empty() || v[s.top()] <= v[i])
            s.push(i++);

        else{
            tp = s.top();
            s.pop();

            area_with_top = v[tp] * (s.empty() ? i: i-s.top()-1);

            maxArea = max(maxArea, area_with_top);
        }
    }

    while(s.empty() == false){
        tp = s.top();
        s.pop();

        area_with_top = v[tp] * (s.empty() ? i: i-s.top()-1);

        maxArea = max(maxArea, area_with_top);
    }

    return maxArea;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        cout << Compute(v,n) << endl;
    }
}