// https://www.geeksforgeeks.org/egg-dropping-puzzle-dp-11/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec2d(v,n,m,init) vector<vector<int>> v(n, vector<int>(m,init))

int recursion(int e, int f){
	if (f==0 || f==1)
		return f;
	if (e==1)
		return f;

	int mintrails = INT_MAX;
	fr(i,1,f){
		mintrails = min(mintrails,max(recursion(e-1,i-1),recursion(e,f-i)));
	}
	return 1+mintrails;
}

int dp(int e, int f){
	vec2d(dp,e+1,f+1,0);

	// 'i" trails for one egg and 'i' floors
	fr(i,0,f)
		dp[1][i] = i;

	// Only one trail for any no.of eggs if there is one floor
	fr(i,1,e)
		dp[i][1] = 1;

	fr(i,2,e){
		fr(j,2,f){
			dp[i][j] = INT_MAX;
			fr(x,1,j){
				dp[i][j] = min(dp[i][j], 1 + max(dp[i-1][x-1], dp[i][j-x]));
			}
		}
	}
	return dp[e][f];
}

int main(){
	int e,f;
	cin >> e >> f;

	cout << "Recursion:" << endl;
	cout << recursion(e,f) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << dp(e,f) << endl;
}