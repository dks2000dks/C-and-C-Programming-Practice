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

void Input_Two_Vector(vector<int> &array, vector<int> &arr, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
		cin >> arr[i];
	}
}

void ProcessData(int S, vector<int> &v1, vector<int> &v2, int n){
    deque<int> Q;
    int time;

    fr(i,0,n-1){
        while(!Q.empty() && Q.front() <= v1[i])
            Q.pop_front();

        if (Q.empty()){
            time = v1[i];
            Q.push_back(time + v2[i]);
            cout << time << endl;
            time = time + v2[i];
        }

        else if (Q.size() < S){
            if (time >= Q.back())
                cout << time << endl;
            Q.push_back(time + v2[i]);
            time = time + v2[i];
        }

        else{
            cout << -1 << endl;
            continue;
        }
    }
}

int main(){
    int S,n;
    cin >> S >> n;

    if (n>0 && S>0){
        vec1d(v1,int,n,0);
        vec1d(v2,int,n,0);
        Input_Two_Vector(v1,v2,n);

        ProcessData(S,v1,v2,n);
    }

    else if (S==0 && n>0){
        vec1d(v1,int,n,0);
        vec1d(v2,int,n,0);
        Input_Two_Vector(v1,v2,n);

        fr(i,0,n-1){
            cout << -1 << endl;
        }
    }


}