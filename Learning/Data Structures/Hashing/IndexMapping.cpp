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
#define Max 1000
bool Hash[Max+1][2];

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

bool Search(int x){
    if (x>=0){
        if (Hash[x][0] == 1)
            return true;
        else
            return false;
    }

    else{
        if (Hash[x][1] == 1)
            return true;
        else
            return false;
    }
}

void Assign(int x){
     if (x>=0)
        Hash[x][0] == 1;

    else
        Hash[x][1] == 1;
    
    return;
}

int main(){
    int n;
    cin >> n;
    vec1d(v,int,n,0);
    Input_Vector(v,n);

    fr(i,0,n-1){
        Assign(v[i]);
    }

    int s;
    cin >> s;
    
    if (Search(s) == true)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;

}
