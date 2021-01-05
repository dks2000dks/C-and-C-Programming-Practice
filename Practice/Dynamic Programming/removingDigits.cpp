// DP Approach
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

int Steps(int n){
	vector<int> v(n+1,1e7);
	v[0] = 0;
	fr(i,1,n){
		int p = i;
		do{
			int d = p%10;
			v[i] = min(v[i],1+v[i-d]);
			p = p/10;
		} while(p>0);
	}
	return v[n];
}
int main(){
	int n;
	cin >> n;
	cout << Steps(n) << endl;
}