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

vector<int> Compute(int n){
    vector<int> output(n,-1);
    int j = 0;

    fr(i,0,n-1){
        int count = 0;
        int limit = i+2;

        while(count < limit){
            if (output[j] == -1 && count == limit-1){
                count++;
            }
            else if (output[j] == -1 && count != limit-1){
                count++;
                j = (j+1)%n;
            }
            else{
                j = (j+1)%n;
            }
        }
        output[j] = i+1;
    }

    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        vector<int> v = Compute(n);

        fr(i,0,n-1){
            cout << v[i] << " ";
        }
        cout << endl;
    }
}