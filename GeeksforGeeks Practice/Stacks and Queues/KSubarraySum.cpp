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

void Print_Vector(vector<int> &v, int n){
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n,k,m, sum;
		cin >> n >> k >> m;

		vec1d(v,int,n,0);
		Input_Vector(v,n);
		
		priority_queue<int> q;

		fr(i,0,n-1){
			if (i < k-1){
				sum += v[i];
			}
			else if (i == k-1){
				sum += v[i];
				q.push(sum);
			}
			else{
				sum = sum + v[i] - v[i-k];
				q.push(sum);
			}
		}

		while(m--){
			cout << q.top() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}