// Source: https://www.geeksforgeeks.org/min-cost-path-dp-6/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void Input_Matrix(vector<vector<int>> &v, int m, int n){
	for (int i = 0; i < m; i++){
		for (int j=0; j<n; j++){
			cin >> v[i][j];
		}
	}
}

int recursion(vector<vector<int>> &v, int m, int n){
	// Path starts from (0,0)
	if (n<0 || m<0)
		return INT_MAX;
	else if (m==0 && n==0)
		return v[m][n];
	else
		return v[m][n] + min(min(recursion(v,m-1,n),recursion(v,m,n-1)),recursion(v,m-1,n-1));
}

int dp(vector<vector<int>> &v, int m, int n){
	vector<vector<int>> matrix(m+1,vector<int> (n+1,0));
	matrix[0][0] = v[0][0];
	fr(i,1,m){
		matrix[i][0] = v[i][0] + matrix[i-1][0];
	}
	fr(i,1,n){
		matrix[0][i] = v[0][i] + matrix[0][i-1];
	}

	fr(i,1,m){
		fr(j,1,n){
			matrix[i][j] = v[i][j] + min(min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]);
		}
	}

	return matrix[m][n];
}

int main(){
	int m,n;
	cin >> m >> n;
	vector<vector<int>> v(m,vector<int> (n,0));
	Input_Matrix(v,m,n);

	cout << "Recursion:" << endl;
	cout << recursion(v, m-1, n-1) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << dp(v, m-1, n-1) << endl;
}