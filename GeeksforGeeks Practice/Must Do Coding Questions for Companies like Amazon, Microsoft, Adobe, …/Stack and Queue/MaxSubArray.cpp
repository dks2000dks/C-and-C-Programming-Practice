#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
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

void MaxSlidingWindow(vector<int> &v, int n, int k){
    deque<int> Q(k);

    fr(i,0,k-1){
        while(!Q.empty() && v[i] >= v[Q.back()])
            Q.pop_back();
        Q.push_back(i);
    }

    fr(i,k,n-1){
        cout << v[Q.front()] << " ";

        while(!Q.empty() && Q.front() <= i-k)
            Q.pop_front();
        
        while(!Q.empty() && v[i] >= v[Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }
    cout << v[Q.front()] << endl;
    return;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n,k;
        cin >> n >> k;
        vec1d(v,int,n,0);
        Input_Vector(v,n);
        MaxSlidingWindow(v,n,k);
    }
}