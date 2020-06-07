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

int coinCombinations(vector<int> &v, int m){
	int limit = 1e9 + 7;
	std::vector<int> paths(m+1,0);

	// Null Set is a possiblility
	paths[0] = 1;

	fr(i,1,m){
		fr(j,0,v.size()-1){
			if (i-v[j] >= 0){
				paths[i] += paths[i-v[j]];
				paths[i] = paths[i] % limit;
			}
		}
	}
	return paths[m];
}

int coinCombinationsunique(vector<int> &v, int m){
	vector<vector<int>> table(m+1, vector<int> (v.size()+1,0));
	int limit = 1e9 + 7;
	table[0][0] = 1;

	fr(i,0,m){
		fr(j,1,v.size()){
			table[i][j] = table[i][j-1];
			if (i - v[j-1] >=0){
				table[i][j] += table[i-v[j-1]][j];
				table[i][j] = table[i][j] %limit;
			}
		}
	}
	return table[m][v.size()];
}



int main(){
	int n,m;
	cin >> n >> m;
	vector<int> v(n);
	Input_Vector(v,n);

	cout << coinCombinationsunique(v,m) << endl;
}