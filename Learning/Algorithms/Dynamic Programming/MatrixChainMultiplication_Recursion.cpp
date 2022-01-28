// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/
#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int computeoperations(vector<int> &dims,int start, int end){
	if (start == end)
		return 0;
	else{
		int min = INT_MAX;
		int count = 0;

		fr(k,start,end-1){
			count = computeoperations(dims,start,k) + computeoperations(dims,k+1,end) + dims[start-1] * dims[k] * dims[end];
			if (count < min)
				min = count;
		}
		return min;
	}
}

int main() {
	int n;
	cin >> n;
	std::vector<int> dims(n,0);
	Input_Vector(dims,n);
	cout << computeoperations(dims,1,n-1) << endl;
}
