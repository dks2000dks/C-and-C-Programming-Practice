// Soruce: https://www.geeksforgeeks.org/partition-problem-dp-18/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec2d(v,n,m,init) vector<vector<bool>> v(n, vector<bool>(m,init))

void Input_Vector(vector<int> &array, int size){
	for (int i = 0; i < size; i++){
		cin >> array[i];
	}
}

bool PossibilitySum(vector<int> &v, int n, int sum){
	if (sum==0)
		return true;
	else if (n==0 && sum!=0)
		return false;
	else if (v[n-1] > sum)
		return PossibilitySum(v,n-1,sum);

	return PossibilitySum(v,n-1,sum) || PossibilitySum(v,n-1,sum-v[n-1]);
}

bool recursion(vector<int> &v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	if (sum%2 != 0)
		return false;
	else{
		int partialsum = sum/2;
		return PossibilitySum(v,n,partialsum);
	}
}

bool dp(vector<int> &v, int n){
	int sum = accumulate(v.begin(),v.end(),0);
	if (sum%2 != 0)
		return false;
	else{
		int partialsum = sum/2;
		vec2d(dp,n+1,partialsum+1,false);

		fr(i,0,n)
			dp[i][0] = true;

		fr(j,1,partialsum)
			dp[0][j] = false;

		fr(i,1,n){
			fr(j,1,partialsum){
				if (j-v[i] >= 0)
					dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i]];
			}
		}
		return dp[n][partialsum];
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> v(n,0);
	Input_Vector(v,n);

	cout << "Recursion:" << endl;
	cout << recursion(v,n) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << dp(v,n) << endl;
}