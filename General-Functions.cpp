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
#define br(i, a, b) for (int i=a; i>=b; i--)
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

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int Print_Matrix(vector< vector<int>> &v, int n, int m){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			cout << v[i][j] << " ";
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