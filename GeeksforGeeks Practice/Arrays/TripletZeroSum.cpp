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

int Print_Matrix(vector< vector<int>> &mat, int n, int m){
	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}


vector<vector<int>> Compute(vector<int> &v){
    int n = v.size();
    vector<vector<int>> output;

    if (n < 3)
        return output;
    
    sort(v.begin(),v.end());

    fr(i,0,n-3){
        int a = v[i];

        if (a>0)
            break;
        
        if (i>0 && a == v[i-1])
            continue;

        int j = i+1;
        int k = n-1;

        while(j<k){
            int b = v[j];
            int c = v[k];

            int sum = a+b+c;

            if (sum == 0){
                output.push_back({a,b,c});
                
                while(j<k && b == v[++j]);
                while(j<k && c == v[--k]);
            }

            else if (sum > 0){
                k--;
            }

            else{
                j++;
            }
        }
    }
    return output;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        vector<vector<int>> o = Compute(v);

        if (o.size() > 0){
            Print_Matrix(o,o.size(),o[0].size());
        }

        else{
            cout << 0 << endl;
        }
    }
}