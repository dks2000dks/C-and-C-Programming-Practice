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

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int main(){
    int T;
    cin >> T;

    while (T--){
        int n,m,kindex;
        cin >> n >> m >> kindex;

        vec1d(v1,int,n,0);
        Input_Vector(v1,n);
        vec1d(v2,int,m,0);
        Input_Vector(v2,m);
        vec1d(v,int,n+m,0);

        int i=0,j=0;
        fr(k,0,n+m-1){

            if (i<n && j<m){
                if (v1[i] <= v2[j]){
                    v[k] = v1[i];
                    i++;
                }

                else{
                    v[k] = v2[j];
                    j++;
                }
            }

            else if (i<n && j>=m){
                v[k] = v1[i];
                i++;
            }

            else{
                v[k] = v2[j];
                j++;
            }

            if (k == kindex-1){
                cout << v[k] << endl;
                break;
            }
        }
    }
    
}