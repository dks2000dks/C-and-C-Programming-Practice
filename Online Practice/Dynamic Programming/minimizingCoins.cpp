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

void Input_Vector(vector<int> &array, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
}

int Coins(vector<int> &v,int m) {
	int maxi = INT_MAX;
	maxi--;

	vector<int> change(m+1,maxi);
	change[0] = 0;

	fr(i,1,m){
		fr(j,0,v.size()-1){
			if (i-v[j] >= 0)
				change[i] = min(change[i],change[i-v[j]]+1);
		}
	}

	if (change[m] == maxi)
		return -1;
	return change[m];
}

int main() {
	int n,m;
	std::cin >> n >> m;
	std::vector<int> v(n);
	Input_Vector(v,n);

	std::cout << Coins(v,m) << endl;
}
