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

void Input_Matrix(vector<vector<int>> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i][0] >> v[i][1];
	}
}

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int> Compute(vector<vector<int>> Operations){
    vector<int> o = {0};
    int n = Operations.size();

    list<int> v;

    fr(i,0,n-1){
        if (Operations[i][0] == 0)
            o.push_back(Operations[i][1]);
    }

    for(int i=n-1;i>=0;i--){
        if (Operations[i][0] == 1){
            if (v.size() == 0){
                v.push_front(Operations[i][1]);
            }
            else{
                v.push_front(Operations[i][1] ^ v.front());
            }
        }
    }

    int i=0;
    o[0] = o[0] ^ v.front();
    i++;
    
    fr(k,0,n-1){
        if (Operations[k][0] == 0){
            o[i] = o[i] ^ v.front();
            i++;
        }
        else{
            v.pop_front();
        } 
    }

    sort(o.begin(),o.end());
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int q;
        cin >> q;

        vec2d(Operations,int,q,2,0);
        Input_Matrix(Operations,q);

        vector<int> o = Compute(Operations);
        Print_Vector(o,o.size());
    }
}