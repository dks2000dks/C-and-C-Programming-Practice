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

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int Kadane(vector<int>&v, int *start, int *finish){
    int n = v.size();
    int sum=0,maxSum=INT_MIN;
    int local_start = 0;
    *finish = -1;

    fr(i,0,n-1){
        sum += v[i];
        if (sum < 0){
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum){
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    else{
        *finish = *start = max_element(v.begin(),v.end()) - v.begin();
        maxSum = v[*start];

        return maxSum; 
    }
}

int Compute(vector<vector<int>> &v, int n, int m){
    int maxSum = INT_MIN;
    int finalleft,finalright,finaltop,finalbottom;

    int l,r;
    int sum,s,f;

    fr(l,0,m-1){
        vec1d(col,int,n,0);
        fr(r,l,m-1){

            fr(i,0,n-1)
                col[i] += v[i][r];

            sum = Kadane(col,&s,&f);

            if (sum > maxSum){
                maxSum = sum;
                finalleft = l;
                finalright = r;
                finaltop = s;
                finalbottom = f;
            }
        }
    }

    /*
    cout << "(Top, Left) (" << finaltop 
         << ", " << finalleft << ")" << endl;  
    cout << "(Bottom, Right) (" << finalbottom  
         << ", " << finalright << ")" << endl; 
    */
    return maxSum;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vec2d(v,int,n,m,0);
        Input_Matrix(v,n,m);
        cout << Compute(v,n,m) << endl;
    }
}