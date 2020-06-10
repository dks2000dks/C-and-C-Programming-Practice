// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
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

int binomialCoefficient(int n, int r){
	if (n==r || r==0)
		return 1;
	else
		return binomialCoefficient(n-1,r-1) + binomialCoefficient(n-1,r);
}

int main(){
	int n,r;
	cin >> n >> r;
	cout << binomialCoefficient(n,r) << endl;
}