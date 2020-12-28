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
#define fr(i, a, b) for (int i = a; i <= b; i++)
#define vec1d(v, T, n, init) vector<T> v(n, init)
#define vec2d(v, T, n, m, init) vector<vector<T>> v(n, vector<T>(m, init))

void Input_Vector(vector<int> &v, int n){
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
}

int BinarySearch(vector<int> v, int l, int r, int search){
    while (l <= r){
        int m = (l + r) / 2;
        if (v[m] == search)
            return m;
        else if (v[m] > search)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

vector<pair<int, int>> ComputePairs(vector<int> &A, vector<int> &B, int s){
    int n = A.size();
    int m = B.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<pair<int, int>> o;
    int j;

    fr(i, 0, n - 1){
        j = BinarySearch(B, 0, m - 1, s - A[i]);
        if (j != -1){
            o.push_back(make_pair(A[i], B[j]));
        }
    }
    return o;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m, s;
        cin >> n >> m >> s;
        vec1d(A, int, n, 0);
        vec1d(B, int, m, 0);
        Input_Vector(A, n);
        Input_Vector(B, m);

        vector<pair<int, int>> o = ComputePairs(A, B, s);

        if (o.size() >= 1){
            fr(i, 0, o.size() - 1){
                if (i != o.size() - 1){
                    cout << o[i].first << " " << o[i].second << ", ";
                }
                else{
                    cout << o[i].first << " " << o[i].second << endl;
                }
            }
        }
        else{
            cout << -1 << endl;
        }
    }
}