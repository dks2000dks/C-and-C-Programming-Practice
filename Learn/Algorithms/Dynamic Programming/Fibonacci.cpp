// Dynamic Programming
// Overlapping Subproblem

// Source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/

#include <bits/stdc++.h>
using namespace std;
#define fr(i, a, b) for (int i=a; i<=b; i++)

int Fibonacci_recursion(int n){
	if (n<=1)
		return n;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}

int Fibonacci(int n){
	int f[n+1];
	f[0] = 0;
	f[1] = 1;

	fr(i,2,n)
	{
		f[i] = f[i-1] + f[i-2];
	}

	return f[n];
}

int main(){
	int n=40;

	cout << "Recursion:" << endl;
	cout << "Fibonacci Number is " << Fibonacci_recursion(n) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << "Fibonacci Number is " << Fibonacci(n) << endl;
	return 0;
}