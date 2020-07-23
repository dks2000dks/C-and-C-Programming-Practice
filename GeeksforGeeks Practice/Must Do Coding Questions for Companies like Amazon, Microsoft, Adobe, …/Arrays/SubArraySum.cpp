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
	for (int i = 0; i < size; i++) cin >> array[i];
}

int subArraySum(vector<int> &v, int s){
    int sum = v[0];
    int n = v.size();
    int a=0;

    fr(b,0,n-1){

        while(sum > s && a <= b){
            sum -= v[a];
            a++;
        }

        if(sum == s){
            cout << a+1 << " " << b+1 << endl;
            return 0;
        }
        
        sum += v[b+1];
    }
    return 1;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n,s;
        cin >> n >> s;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        if (subArraySum(v,s))
            cout << -1 << endl;
    }
}