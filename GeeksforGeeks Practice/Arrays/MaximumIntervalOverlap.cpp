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

void Print_Vector(vector<pair<int,int>> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i].first << " to " << array[i].second << "  ";
	}
	cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v;
        int t;

        fr(i,0,n-1){
            cin >> t;
            v.push_back(make_pair(t,-1));
        }

        fr(i,0,n-1){
            cin >> t;
            v.push_back(make_pair(t,1));
        }

        sort(v.begin(),v.end());

        int maxp = 0;
        int time = 0;
        int currp = 0;

        fr(i,0,2*n - 1){
            currp += v[i].second;
            if (currp < maxp){
                maxp = currp;
                time = v[i].first;
            }
        }

        cout << abs(maxp) << " " << time << endl;
    }
}