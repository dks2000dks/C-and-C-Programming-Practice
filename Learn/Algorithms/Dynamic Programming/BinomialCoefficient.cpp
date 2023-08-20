//https://www.geeksforgeeks.org/binomial-coefficient-dp-9/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec2d(v,n,m,init) vector<vector<int>> v(n, vector<int>(m,init))

int binomialCoefficient_recursion(int n, int r){
	if (n==r || r==0)
		return 1;
	else
		return binomialCoefficient(n-1,r-1) + binomialCoefficient(n-1,r);
}

int binomialCoefficient(int n, int r){
	vec2d(dp,n+1,r+1,0);
	
	fr(i,0,n){
		dp[i][0] = 1;
	}

	fr(i,0,n){
		fr(j,1,r){
			if (i >= j && j>=1 && i >=1){
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
			}
		}
	}
	return dp[n][r];
}

int main(){
	int n,r;
	cin >> n >> r;
	
	cout << "Recursion:" << endl;
	cout << binomialCoefficient_recursion(n,r) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << binomialCoefficient(n,r) << endl;
}