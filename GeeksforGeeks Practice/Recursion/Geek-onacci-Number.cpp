#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))
#define PI 3.1415926535897932384626
const int mod = 1000000007;

int Solve(int n, int &a, int &b, int &c){
	if (n == 1) return a;
	else if (n == 2) return b;
	else if (n == 3) return c;
	else return Solve(n-1,a,b,c) + Solve(n-2,a,b,c) + Solve(n-3,a,b,c);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int a,b,c,n;
		cin >> a >> b >> c >> n;
		cout << Solve(n,a,b,c) << endl;
	}

	return 0;
}