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

// Hash Matrix
#define Max 10000000
vec1d(Hash,string,Max,"not found");

string Find(int x){
    return Hash[x];
}

void Add(int x, string contant){
    Hash[x] = contant;
}

void Delete(int x){
    Hash[x] = "not found";
}

int main(){
    int n;
    cin >> n;
    
    while(n--){
        string operation;
        cin >> operation;
        
        if (operation == "add"){
            int number;
            string name;
            cin >> number >> name;
            Add(number,name);
        }

        else if (operation == "find"){
            int number;
            cin >> number;
            cout << Find(number) << endl;
        }

        else{
            int number;
            cin >> number;
            Delete(number);
        }
    }
}
