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

int main(){
	// Declaring a Variable
	int variable = 20;
	cout << "variable = " << variable << endl;

	// Assigning a Pointer to Address of Variable
	int pr = &variable;

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