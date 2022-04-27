#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))
#define PI 3.1415926535897932384626
const int mod = 1000000007;

void Input_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
}

int getBinaryKey(int k){
	int o = 0;
	while(k){
		o = o | (1<<(k%10));
		k = k/10;
	}
	return o;
}

int Fill(int k, vector<int> &dp, vector<int> &v, int n){
	if (k == 0)
		return 0;
	if (dp[k] != -1)
		return dp[k];

	int key;
	fr(i,0,n-1){
		key = getBinaryKey(v[i]);
		if ((key | k) == k)
			dp[k] = max(max(0, dp[k^key]) + v[i], dp[k]);
	}	

	return dp[k];
}

int Solve(vector<int> &v, int n){
	vec1d(dp,int,1024,-1);
	int o = 0;

	fr(i,0,1023){
		o = max(o, Fill(i,dp,v,n));
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vec1d(v,int,n,0);
		Input_Vector(v,n);
		cout << Solve(v,n) << endl;
	}

	return 0;
}