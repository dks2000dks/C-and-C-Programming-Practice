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

struct petrolPump{
    int petrol;
    int distance;
};

int tour (petrolPump p[], int n){

    int start = 0; 
    int end = 1; 

    int petrolleft = p[start].petrol - p[start].distance; 


    while (end != start || petrolleft < 0) 
    { 
        while (petrolleft < 0 && start != end) 
        { 
            petrolleft -= p[start].petrol - p[start].distance; 
            start = (start + 1) % n; 
            if (start == 0) 
                return -1; 
        } 

        petrolleft += p[end].petrol - p[end].distance; 

        end = (end + 1) % n; 
    } 

    return start;  
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        petrolPump p[n];

        fr(i,0,n-1) cin >> p[i].petrol >> p[i].distance;
        
        cout << tour(p,n) << endl;
    }
}