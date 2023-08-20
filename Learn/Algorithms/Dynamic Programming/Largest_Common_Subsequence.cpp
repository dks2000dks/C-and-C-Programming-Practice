// Source: https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void Input_Vector(vector<int> &array, int size){
	int x;
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int LCS_recursion(char *X, char *Y, int m, int n){
	if (m==0 || n==0)
		return 0;

	if (X[m-1] == Y[n-1])
		return 1 + LCS(X,Y,m-1,n-1);
	else
		return max(LCS(X,Y,m-1,n), LCS(X,Y,m,n-1));
}

int LCS(char *X, char *Y, int m, int n){
	int table[m+1][n+1];

	fr(i,0,m){
		fr(j,0,n){
			if (i==0 || j==0)
				table[i][j] = 0;
			else if (X[i-1] == Y[j-1])
				table[i][j] = table[i-1][j-1] + 1;
			else
				table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[m][n];
}

int main(){
	int m,n;
	cin >> m >> n;
	char X[m],Y[n];
	cin >> X;
	cin >> Y;

	cout << "Recursion:" << endl;
	cout << LCS_recursion(X,Y,m,n) << endl;
	cout << endl;
	cout << "DP:" << endl;	
	cout << LCS(X,Y,m,n) << endl;
}