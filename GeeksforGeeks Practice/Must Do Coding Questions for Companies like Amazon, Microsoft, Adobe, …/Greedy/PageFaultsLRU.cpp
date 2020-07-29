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
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int Process(vector<int> &pages, int n, int capacity){

	unordered_set<int> s; 
	unordered_map<int, int> indexes; 

	int pf = 0; 
	for (int i=0; i<n; i++) {
        if (s.size() < capacity) { 
			if (s.find(pages[i])==s.end()) { 
				s.insert(pages[i]); 
				pf++; 
			} 
			indexes[pages[i]] = i; 
		} 

		else{ 
			if (s.find(pages[i]) == s.end()) { 
				int lru = INT_MAX, val; 
				for (auto it=s.begin(); it!=s.end(); it++) { 
					if (indexes[*it] < lru) { 
						lru = indexes[*it]; 
						val = *it; 
					} 
				} 

				s.erase(val); 
				s.insert(pages[i]); 
				pf++;
			} 
			indexes[pages[i]] = i; 
		} 
	}
	return pf; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        int cap;
        cin >> cap;

        cout << Process(v,v.size(),cap) << endl;
    }
}