// Source: https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

int knapsack_recursion(vector<int> &cost, vector<int> &weights, int n, int w){
	if (n==0 || w==0)
		return 0;

	if(weights[n-1] > w)
		return knapsack_recursion(cost,weights,n-1,w);

	else
		return max(cost[n-1] + knapsack_recursion(cost,weights,n-1,w-weights[n-1]), knapsack_recursion(cost,weights,n-1,w));
}

int knapsack(vector<int> &cost, vector<int> &weights, int n, int w){
	vector<vector<int>> dp(n+1,vector<int> (w+1,0));

	fr(i,1,n){
		fr(j,1,w){
			if (j-weights[i-1] >= 0)
				dp[i][j] = max(dp[i-1][j], cost[i-1] + dp[i-1][j-weights[i-1]]);
			else
				dp[i][j] = dp[i-1][j];
		}
	}
	return dp[n][w];
}

int main(){
	int n,w;
	cin >> n >> w;
	vector<int> cost(n),weights(n);
	Input_Vector(cost,n);
	Input_Vector(weights,n);

	cout << "Recursion:" << endl;
	cout << knapsack_recursion(cost,weights,n,w) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << knapsack(cost,weights,n,w) << endl;
}