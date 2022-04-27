#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))
#define PI 3.1415926535897932384626
const int mod = 1000000007;

int Solve(int n){
	vec1d(v,int,n+1,0);
	v[1] = 1;

	fr(i,2,n)
		v[i] = (v[i-1] + v[i-2])%100;

	return v[n];
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << Solve(n%300) << endl;
	}

	return 0;
}