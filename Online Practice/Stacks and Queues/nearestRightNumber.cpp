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

void nearestSmallerNumber(vector<int> &v, int n){
	stack<int> s;
	stack<int> t;
	s.push(v[n-1]);

	for(int i=n-1;i>=0;i--){
		if (i==n-1){
			t.push(-1);
			continue;
		}

		s.push(v[i]);

		while(!s.empty() && s.top() >= v[i])
			s.pop();

		if (!s.empty())
			t.push(s.top());
		else
			t.push(-1);

		s.push(v[i]);
	}

	while(!t.empty()){
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
}

void nearestGreaterNumber(vector<int> &v, int n){
	stack<int> s;
	stack<int> t;
	s.push(v[n-1]);

	for(int i=n-1;i>=0;i--){
		if (i==n-1){
			t.push(-1);
			continue;
		}

		s.push(v[i]);

		while(!s.empty() && s.top() <= v[i])
			s.pop();

		if (!s.empty())
			t.push(s.top());
		else
			t.push(-1);

		s.push(v[i]);
	}

	while(!t.empty()){
		cout << t.top() << " ";
		t.pop();
	}
	cout << endl;
}

int main(){
	int n;
	cin >> n;
	vec1d(v,int,n,0);
	Input_Vector(v,n);

	nearestSmallerNumber(v,n);
	nearestGreaterNumber(v,n);
}