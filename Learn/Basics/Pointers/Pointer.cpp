// Source Link: https://www.geeksforgeeks.org/cpp-pointers/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int main(){
	// Declaring a Variable
	int variable = 20;
	cout << "variable = " << variable << endl;

	// Assigning a Pointer to the Address of Variable
	int* pr = &variable;

	// Printing the Address of Variable
	cout << "&variable = " << &variable << endl;

	// Printing Pointer Variable
	cout << "pr = " << pr << endl;

	// Printing Pointed Value
	cout << "*pr = " << *pr << endl;
}

/*
The reason we associate data type to a pointer is that it knows how many bytes the data is stored in.
When we increment a pointer, we increase the pointer by the size of data type to which it points.
*/