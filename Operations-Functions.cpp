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

// 2-Sum Problem.
// Checking if Sum of any 2 Elements in Array is equal to given value or Not
bool isPairPresent(vector<int> v, int target)
{
    int n = v.size();
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        int temp = target - v[i];
        if (s.find(temp) != s.end())
            return true;

        s.insert(v[i]);
    }
    return false;
}

// Merging 2 Sorted Arrays
vector<int> MergingSortedArrays(vector<int> &v1, vector<int> &v2){
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