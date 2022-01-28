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

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vec1d(start,int,n,0);
        fr(i,0,n-1){
            cin >> start[i];
        }

        vec1d(end,int,n,0);
        
        fr(i,0,n-1){
            cin >> end[i];
        }

        vector<pair<int,int>> time;
        fr(i,0,n-1){
            time.push_back(pair<int,int>(end[i],start[i]));
        }

        sort(time.begin(),time.end());

        int count = 1;
        int i = 0;

        fr(j,1,n-1){
            if (time[j].second >= time[i].first){
                i = j;
                count++;
            }
        }
        cout << count << endl;
    }
}