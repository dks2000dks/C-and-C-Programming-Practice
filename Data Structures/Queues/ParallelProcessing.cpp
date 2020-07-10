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

typedef pair<long long int, int> pi; 

void Scheduler(vector<int> q, int t){
    priority_queue<pi, vector<pi>, greater<pi> > threads;

    fr(i,0,t-1){
        cout << i << " " << 0 << endl;
        threads.push(make_pair(q[i],i));
    }

    fr(i,t,q.size()-1){
        
        pair<long long int, int> top = threads.top();
        threads.pop();

        int tindex = top.second;
        long long int tvalue = top.first;
        
        cout << tindex << " " << tvalue << endl;

        tvalue = tvalue + q[i];

        threads.push(make_pair(tvalue, tindex));  
    }
}

int main(){
    int t,n;
    cin >> t >> n;

    vector<int> q;

    fr(i,0,n-1){
        int x;
        cin >> x;
        q.push_back(x);
    }

    Scheduler(q,t);
}