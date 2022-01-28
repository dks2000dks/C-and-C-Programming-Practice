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

int Compute(vector<int> &start, vector<int> end){
    
    vector<pair<int,int>> m;
    int n = start.size();
    
    for(int i=0;i<n;i++){
        m.push_back(make_pair(start[i],0));
        m.push_back(make_pair(end[i],1));
    }
    
    sort(m.begin(),m.end());
    
    int maxActive=0,Active=0;
    
    for(int i=0;i<m.size();i++){
        
        if (m[i].second == 0){
            Active++;
            maxActive = max(maxActive,Active);
        }
        
        else{
            Active--;
        }
    }
    
    return maxActive;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        
        vec1d(start,int,n,0);
        vec1d(end,int,n,0);
        
        fr(i,0,n-1){
            cin >> start[i];
        }
        
        fr(i,0,n-1){
            cin >> end[i];
        }
        
        cout << Compute(start,end) << endl;
    }
}