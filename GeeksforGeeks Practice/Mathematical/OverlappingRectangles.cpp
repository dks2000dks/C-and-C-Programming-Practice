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
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

bool CheckOverlap(vector<int> &A, vector<int> &B){
    if (A[0] > B[2] || B[0] > A[2])
        return false;
    if (A[3] > B[1] || B[3] > A[1])
        return false;
    return true;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        vec1d(A,int,4,0);
        vec1d(B,int,4,0);
        vec1d(C,int,4,0);

        Input_Vector(A,4);
        Input_Vector(B,4);

        if (CheckOverlap(A,B))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}