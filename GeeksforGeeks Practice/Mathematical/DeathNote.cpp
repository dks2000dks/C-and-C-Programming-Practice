#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))
#define PI 3.1415926535897932384626
const int mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int k,n,m;
		cin >> k;
		int first = 0;

		fr(i,0,k-1){
			cin >> n >> m;
			first ^= ((n+m-2)%3);
		}

		if (first == 0) cout << "EL" << endl;
		else cout << "Light" << endl;
	}

	return 0;
}