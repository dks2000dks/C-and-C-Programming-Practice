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

void Input_Vector(vector<string> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int Compare(string a, string b){
    if (stoi(a+b) >= stoi(b+a))
        return 0;
    else
        return 1;
}

vector<string> Generate(vector<string> &v, int n){
    int stop = 1;
    while(stop){
        stop = 0;
        fr(i,0,n-2){
            string a = v[i];
            string b = v[i+1];
            if (Compare(a,b)){
                stop = 1;
                v[i] = b;
                v[i+1] = a;
            }
        }
    }

    return v;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<string> v(n);
        Input_Vector(v,n);
        v = Generate(v,n);
        string s = "";
        fr(i,0,n-1) s = s+v[i];
        cout << s << endl;
    }
}