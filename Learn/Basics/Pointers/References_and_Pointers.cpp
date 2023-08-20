// Source Link: https://www.geeksforgeeks.org/cpp-pointers/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

/*
There are 3 ways to pass C++ arguments to a function:

1) Call-by-Value
2) Call-by-Reference with Pointer Argument
3) Call-by-Reference with Reference Argument
*/

// Pass by Value
int Square1(int a){
	// Address of 'a' in Square1() is not same as in main().
	// A clone is created.
	cout << "Address of 'a' in function Square1() = " << &a << endl;

	// Clone is Modified in the Function
	a *=a;
	return a;
}

// Pass by Reference with Pointer Argument
void Square2(int *b){
	// Address of 'b' in Square2() is same as in main().
	cout << "Address of 'b' in function Square2() = " << b << endl;

	// Explicit De-Referencing to get the Value Pointed-to
	*b *= *b;
}

// Pass by Reference with Reference Argument
void Square3(int &c){
	// Address of 'c' in Square3() is same as in main().
	cout << "Address of 'c' in function Square3() = " << &c << endl;

	// Implicit De-Referencing (without '*')
	c *= c;
}

int main(){
	int a=10,b=8,c=6;

	// Pass by Value
	cout << "Address of 'a' in main() = " << &a << endl;
	cout << "Square1(a) = " << Square1(a) << endl;
	cout << "a = " << a << endl;
	// Value of 'a' is not changed
	cout << "---------------------------------" << endl;

	// Pass by Reference with Pointer Argument
	cout << "Address of 'b' in main() = " << &b << endl;
	Square2(&b);
	cout << "b = " << b << endl;
	// Value of 'b' is changed
	cout << "---------------------------------" << endl;

	// Pass by Reference with Reference Argument
	cout << "Address of 'c' in main() = " << &c << endl;
	Square3(c);
	cout << "c = " << c << endl;
	// Value of 'c' is changed.
	cout << "---------------------------------" << endl;
}
