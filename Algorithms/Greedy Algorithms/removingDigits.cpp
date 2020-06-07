//Greedy Approach
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
	int count=0;
	while(n>0){
		int m=0;
		int p = n;
		do{
			int digit = p%10;
			m = max(digit,m);
			p = p/10;
		} while(p>0);
		n = n-m;
		count++;
	}
	return count;
}
int main(){
	int n;
	cin >> n;
	cout << Steps(n) << endl;
}