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
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

vector<int> calculateSpan(vector<int> price,int n){
	vec1d(s,int,n,0);
	stack<int> st;
	st.push(0);

	s[0] = 1;

	fr(i,1,n-1){
		while(!st.empty() && price[st.top()] <= price[i])
			st.pop();

		if (st.empty())
			s[i] = i+1;
		else
			s[i] = i-st.top();

		st.push(i);
	}
	return s;
}

int main(){
	int n;
	cin >> n;

	vec1d(price,int,n,0);
	Input_Vector(price,n);

	vector<int> v = calculateSpan(price,n);
	Print_Vector(v,n);
}

