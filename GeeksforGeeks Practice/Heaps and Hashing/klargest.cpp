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

void Compute(int n, int k){
    priority_queue<int, vector<int>, greater<int>> minHeap;

    fr(i, 0, n - 1){
        int x;
        cin >> x;
        
        if (minHeap.size() < k){
            minHeap.push(x);
            if (minHeap.size() == k)
                cout << minHeap.top() << " ";
            else
                cout << -1 << " ";
        }

        else{
            if (x > minHeap.top() && minHeap.size() == k){
                minHeap.pop();
                minHeap.push(x);
            }

            cout << minHeap.top() << " ";
        }
    }
    cout << endl;
}


int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> k >> n;

        Compute(n, k);
    }
}