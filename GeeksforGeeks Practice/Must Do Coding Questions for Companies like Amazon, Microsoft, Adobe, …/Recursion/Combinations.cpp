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

void Print(vector<int> soFar){
    cout << "(";
    fr(i,0,soFar.size()-1){
        if (i!= soFar.size()-1)
            cout << soFar[i] << " ";
        else
            cout << soFar[i];
        
    }
    cout << ")";
}

void Combinations(vector<int> &v, int sum, int index, vector<int> soFar, set<vector<int>> &SetofVectors){
    if (sum==0){
        sort(soFar.begin(),soFar.end());
        SetofVectors.insert(soFar);
        return;
    }

    else if (sum < 0){
        return;
    }

    else{
        if (index < v.size()){

            soFar.push_back(v[index]);
            Combinations(v,sum-v[index],index+1,soFar,SetofVectors);
            soFar.pop_back();
            Combinations(v,sum,index+1,soFar,SetofVectors);
        }

        return;
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        int s;
        cin >> s;

        vector<int> soFar;
        set<vector<int>> SetofVectors;

        Combinations(v,s,0,soFar,SetofVectors);

        if (SetofVectors.size()){
            for (auto it = SetofVectors.begin(); it != SetofVectors.end(); it++) {
                Print(*it); 
            }
            cout << endl;
        }
        else{
            cout << "Empty" << endl;
        }
    }
}