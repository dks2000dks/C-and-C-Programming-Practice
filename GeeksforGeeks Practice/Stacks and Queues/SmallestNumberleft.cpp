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

vector<int> Compute(vector<int> &v, int n){
    stack<int> s;
    vector<int> o(n,0);
    s.push(-1);

    fr(i,0,n-1){
        if (i==0){
            o[i] = s.top();
            s.pop();
            s.push(v[i]);
        }
        else{
            while (!s.empty() && s.top() >= v[i]){
                s.pop();
            }

            if (s.empty()){
                o[i] = -1;
            }
            else{
                o[i] = s.top();
            }

            s.push(v[i]);
        }
    }
    return o;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        vector<int> o = Compute(v,n);
        Print_Vector(o,n);
    }
}