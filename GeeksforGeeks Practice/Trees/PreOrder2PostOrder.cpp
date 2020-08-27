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

void findPostOrderUtil(vector<int> &pre, int n, int minval, int maxval, int& preIndex) 
{ 

    if (preIndex == n) 
        return; 

    if (pre[preIndex] < minval || pre[preIndex] > maxval) { 
        return; 
    } 
  
    int val = pre[preIndex]; 
    preIndex++; 
  

    findPostOrderUtil(pre, n, minval, val, preIndex); 
    findPostOrderUtil(pre, n, val, maxval, preIndex); 
  
    cout << val << " "; 
} 

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        Input_Vector(v,n);

        int preIndex = 0;
        findPostOrderUtil(v,n,INT_MIN,INT_MAX,preIndex);
    }
}