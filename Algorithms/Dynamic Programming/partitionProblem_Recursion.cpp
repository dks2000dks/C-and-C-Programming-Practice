// https://www.geeksforgeeks.org/partition-problem-dp-18/
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

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

bool PossibilitySum(vector<int> &v, int n, int sum){
	if (sum==0)
		return true;
	else if (n==0 && sum!=0)
		return false;
	else if (v[n-1] > sum)
		return PossibilitySum(v,n-1,sum);

	return PossibilitySum(v,n-1,sum) || PossibilitySum(v,n-1,sum-v[n-1]);
}

bool Result(vector<int> &v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	if (sum%2 != 0)
		return false;
	else{
		int partialsum = sum/2;
		return PossibilitySum(v,n,partialsum);
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	Input_Vector(v,n);
	cout << Result(v,n) << endl;
}