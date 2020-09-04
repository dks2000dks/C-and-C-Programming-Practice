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

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n,m;
        cin >> n >> m;

        priority_queue<int,vector<int>, greater<int>> pq;
        unordered_map<int,int> mp;
        vector<int> ref(m,0);

        vec1d(o,int,n,0);

        int x;
        fr(i,0,n-1){
            cin >> x;
            if (mp.find(x) == mp.end())
                mp[x] = 1;
            else
                mp[x]++;
        }

        int ind = 0;
        fr(i,0,m-1){
            cin >> x;

            int t = mp[x];

            while(t--){
                o[ind] = x;
                ind++;
            }

            mp.erase(x);
        }

        for(auto it:mp){
            int t = it.second;
            x = it.first;

            while(t--){
                pq.push(x);
            }
        }

        for(int i=ind;i<n;i++){
            o[i] = pq.top();
            pq.pop();
        }

        Print_Vector(o,n);
    }
}