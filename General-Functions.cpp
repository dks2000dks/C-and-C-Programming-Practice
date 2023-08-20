#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
#include <string>
#include <math.h>
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

// Main Function
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		
	}
}


class Node{
	// Node
	public:
		int data;
		Node* left;
		Node* right;
};


void Input_Vector(vector<int> &v, int n){
	// Take "n" elements as input for a vector "v".

	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

void Print_Vector(vector<int> &v, int n){
	// Print "n" elements of a vector "v".

	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	// Take elements by each row and column as input to a matrix "v" with "m" rows and "n" columns.

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

void Print_Matrix(vector< vector<int>> &v, int n, int m){
	// Print elements by each row and column of a matrix "v" with "m" rows and "n" columns.

	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

void Input_Array(int *v, int size){
	// Take "n" elements as input for an array "v".
	for (int i = 0; i < size; i++){
		cin >> v[i];
	}
}

void Print_Array(int *v, int size){
	// Print "n" elements of an array "v".
	for (int i = 0; i < size; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

vector<int> SubVector(vector<int> const &v, int m, int n){
	// Return a subvector of vector "v" with starting index "m" and ending index "n" both indices included.

	auto first = v.begin() + m;
	auto last = v.begin() + n + 1;
	vector<int> vector(first, last);
	return vector;
}