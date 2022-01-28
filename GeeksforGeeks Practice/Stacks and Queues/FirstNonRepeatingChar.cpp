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

void Input_Vector(vector<char> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Check(vector<char> &v){
    deque <char> unique;
    deque <char> all;
    deque <char> check;

    int n = v.size();
    fr(i,0,n-1){
        char c = v[i];

        if (i==0){
            unique.push_back(c);
            all.push_back(c);
            cout << c << " ";
            continue;
        }

        // Checking Occurence
        int count=0,v=1;
        while(count != all.size()){
            if (c == all.front()){
                v = 0;
            }
            char inter = all.front();
            all.pop_front();
            all.push_back(inter);
            count++;
        }

        // v==0 -- Occured Previously
        // v==1 -- Not Occured Previously

        // Removing it from Unique Elements if Present
        if (v==0){

            while(!unique.empty()){
                if (unique.front() != c)
                    check.push_back(unique.front());
                unique.pop_front();
            }

            unique.clear();
            unique = move(check);
            check.clear();
        }

        // Adding it
        else{
            all.push_back(c);
            unique.push_back(c);
        }

        if (unique.empty())
            cout << -1 << " ";
        else
            cout << unique.front() << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,char,n,'0');
        Input_Vector(v,n);
        Check(v);
    }
}