// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/
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
#define vec2d(v,n,m,init) vector<vector<int>> v(n, vector<int>(m,init))

int compute(int e, int f){
	if (f==0 || f==1)
		return f;
	if (e==1)
		return f;

	int mintrails = INT_MAX;
	fr(i,1,f){
		mintrails = min(mintrails,max(compute(e-1,i-1),compute(e,f-i)));
	}
	return 1+mintrails;
}

int main(){
	int e,f;
	cin >> e >> f;
	cout << compute(e,f) << endl;
}