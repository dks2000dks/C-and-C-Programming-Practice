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

void func1(){
	int val[3] = {5,10,20};
	int *ptr;
	ptr = val;
	cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << endl;
	cout << "--------------------------------------" << endl;

	fr(i,0,2){
		cout << "Value of ptr = " << ptr << endl;
		cout << "Value of *ptr = " << *ptr << endl;
		ptr++;
	}
}

void func2(){
	int matrix[2][3] = {{1,2,3},{4,5,6}};
	fr(i,0,1){
		fr(j,0,2){
			cout << *(*(matrix+i)+j) << " ";
		}
		cout << endl;
	}
}

int main(){
	func1();
	func2();

	const char *ptr = "geek";
	cout << *(ptr+2) << endl;
	cout << ptr[3] << endl;
}