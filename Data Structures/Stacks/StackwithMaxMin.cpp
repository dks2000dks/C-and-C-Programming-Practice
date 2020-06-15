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

class StackwithMaxMin{
	stack <int> mainStack;
	stack <int> maxStack;
	stack <int> minStack;

public:
	void push(int x){
		mainStack.push(x);
		if (mainStack.size() == 1){
			maxStack.push(x);
			minStack.push(x); 
		}

		if (x > maxStack.top())
			maxStack.push(x);
		else
			maxStack.push(maxStack.top());

		if (x < minStack.top())
			minStack.push(x);
		else
			minStack.push(minStack.top());
	}

	int pop(){
		mainStack.pop();
		maxStack.pop();
		minStack.pop();
	}

	int getMax(){
		return maxStack.top();
	}

	int getMin(){
		return minStack.top();
	}
};


int main(){
	StackwithMaxMin s;
	s.push(20);
	cout << s.getMax() << endl;
	cout << s.getMin() << endl;
	s.push(10);
	cout << s.getMax() << endl;
	cout << s.getMin() << endl;
	s.push(50);
	cout << s.getMax() << endl;
	cout << s.getMin() << endl; 
}