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

vector<int> MergingSortedArrays(vector<int> &v1, vector<int> &v2, ll &inv){
    int i=0, j=0;
    int n = v1.size();
    int m = v2.size();
    vector<int> v(m+n,0);

    fr(k,0, n+m-1){
        if (i < n && j < m){
            if (v1[i] <= v2[j]){
                v[k] = v1[i];
                i++;
            }

            else{
                v[k] = v2[j];
                inv += n-i;
                j++;
            }
        }

        else if (i < n && j >= m){
            v[k] = v1[i];
            i++;
        }

        else{
            v[k] = v2[j];
            j++;
        }
    }
    return v;
}

vector<int> MergeSort(vector<int> &v, int l, int r, ll &inv){
    if(l == r)
        return {v[l]};

    int mid = (l+r)/2;

    vector<int> left = MergeSort(v, l, mid, inv);
    vector<int> right = MergeSort(v, mid+1, r, inv);

    return MergingSortedArrays(left,right,inv);
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        ll inv = 0;
        MergeSort(v, 0, v.size()-1, inv);
        cout << inv << endl;
    }
}