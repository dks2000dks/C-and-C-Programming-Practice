// Source Link: https://www.geeksforgeeks.org/stack-in-cpp-stl/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int main(){
	// Declaring Stack
	stack <int> s;

	// push Operation
	fr(i,0,10){
		s.push(10*i);
	}

	// pop Operation
	s.pop();

	// Size of Stack
	cout << s.size() << endl;

	// Check Empty Operation
	cout << s.empty() << endl;

	// Top Element Operation
	cout << s.top() << endl;

	stack <int> sa;
	fr(i,0,10){
		sa.push(i*9);
	}

	// Swap Operations
	s.swap(sa);
	// Switches names of Stacks

	// Emplace Operation
	sa.emplace(100);
	// Adds Element on the Top
}