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

struct myComp{
    bool operator()(pair<int, int> const& a, pair<int, int> const& b) {
        if (a.first == b.first) 
		    return a.second > b.second;
        return a.first < b.first;
	} 
}; 

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        unordered_map<int,int> mp;

        vec1d(o,int,n,0);

        int x;
        fr(i,0,n-1){
            cin >> x;
            if (mp.find(x) == mp.end())
                mp[x] = 1;
            else
                mp[x]++;
        }

        typedef pair<int, int> pi;
        priority_queue<pi, vector<pi>, myComp> pq; 

        for(auto i:mp){
            pq.push(make_pair(i.second,i.first));
        }

        for(int i=0;i<n;i++){
            int t = pq.top().first;
            int x = pq.top().second;
            pq.pop();

            while(t--){
                o[i] = x;
                i++;
            }
            i--;
        }

        Print_Vector(o,n);
    }
}