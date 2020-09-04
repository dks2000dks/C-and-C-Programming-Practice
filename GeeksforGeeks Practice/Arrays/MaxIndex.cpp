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

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        if (n==1)
            cout << 0 << endl;
        else{
            int maxlen = INT_MIN;

            vec1d(leftmin,int,n,0);
            vec1d(rightmax,int,n,0);

            leftmin[0] = v[0];
            rightmax[n-1] = v[n-1];

            fr(i,1,n-1){
                leftmin[i] = min(v[i],leftmin[i-1]);
            }

            for(int i=n-2;i>=0;i--){
                rightmax[i] = max(v[i],rightmax[i+1]);
            }

            int i=0,j=0;
            while(i<n && j<n){
                if (leftmin[i] <= rightmax[j]){
                    maxlen = max(j-i,maxlen);
                    j++;
                }
                else{
                    i++;
                }
            }

            cout << maxlen << endl;
        }
    }
}