#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define br(i, a, b) for (int i=a; i>=b; i--)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))
#define PI 3.1415926535897932384626
const int mod = 1000000007;

bool Check(string s){
	int n = s.length();
	int sum = 0;
	fr(i,0,n-1){
		if (i < n/2) sum += (s[i] - '0');
		else sum -= (s[i] - '0');
	}

	if (sum == 0) return true;
	else return false;	
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		int n = s.length(), k, p = 0;
		if (n%2 == 0){
			k = n;
		}
		else{
			k = n-1;
		}

		while(k > 0){
			fr(i,0,n-k){
				if (Check(s.substr(i,k))){
					p = 1;
					break;
				}
			}
			if (p == 1)	break;
			else k = k-2;
		}
		cout << k << endl;
	}

	return 0;
}