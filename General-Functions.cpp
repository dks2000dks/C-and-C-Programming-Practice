#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int main(){
    int t;
    cin >> t;
    while(t--){
        
    }
}

// Node
class Node{
public:
    int data;
    Node* left;
    Node* right;
};

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

void Print_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

int Print_Matrix(vector< vector<int>> &mat, int n, int m){
	for (int i=0;i<n;i++){
		for (int j =0;j<m;j++){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

vector<int> SubVector(vector<int> const &v, int m, int n){
	auto first = v.begin() + m;
	auto last = v.begin() + n + 1;
	vector<int> vector(first, last);
	return vector;
}