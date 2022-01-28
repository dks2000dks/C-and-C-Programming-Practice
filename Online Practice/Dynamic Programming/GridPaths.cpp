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

int main(){
	int n;
	cin >> n;

	vector<vector<int>> table(n, vector<int> (n,0));
	int lim = 1e9 + 7;
	table[0][0] = 1;

	fr(i,0,n-1){
		string grid;
		cin >> grid;
		fr(j,0,n-1){
			if (grid[j] == '*')
				table[i][j] = 0;
			else{
				if (i>0){
					table[i][j] += table[i-1][j];
					table[i][j] %= lim;
				}
				if (j>0){
					table[i][j] += table[i][j-1];
					table[i][j] %= lim;			
				}
			}
		}
	}

	cout << table[n-1][n-1] << endl;
}