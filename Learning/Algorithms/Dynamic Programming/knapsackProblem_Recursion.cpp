//0-1 Knapsnack Problem
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

int compute(vector<int> &cost, vector<int> &weights, int n, int w){
	if (n==0 || w==0)
		return 0;

	if(weights[n-1] > w)
		return compute(cost,weights,n-1,w);

	else
		return max(cost[n-1] + compute(cost,weights,n-1,w-weights[n-1]), compute(cost,weights,n-1,w));
}

int main(){
	int n,w;
	cin >> n >> w;
	vector<int> cost(n),weights(n);
	Input_Vector(cost,n);
	Input_Vector(weights,n);

	cout << compute(cost,weights,n,w) << endl;
}