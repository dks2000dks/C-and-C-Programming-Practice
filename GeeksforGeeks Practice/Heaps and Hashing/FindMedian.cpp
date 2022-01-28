//https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/

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

int main(){
    int n;
    cin >> n;

    vector<int> Elements;
    int prevMedian = 0;
    int Median;

    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    fr(i,0,n-1){
        int x;
        cin>>x;
        
        if (i==0){
            maxHeap.push(x);
            Median = x;
        }

        else{
            if (maxHeap.size() > minHeap.size()){
                if (x<Median){
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(x);
                }
                else{
                    minHeap.push(x);
                }

                Median = (minHeap.top() + maxHeap.top())/2;
            }

            else if (maxHeap.size() < minHeap.size()){
                if (x>Median){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(x);
                }
                else{
                    maxHeap.push(x);
                }

                Median = (minHeap.top() + maxHeap.top())/2;
            }

            else{
                if (x<Median){
                    maxHeap.push(x);
                    Median = maxHeap.top();
                }
                else{
                    minHeap.push(x);
                    Median = minHeap.top();
                }
            }
        }

        cout << Median << endl;
    }
}