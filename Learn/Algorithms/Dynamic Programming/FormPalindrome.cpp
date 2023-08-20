// Source: https://www.geeksforgeeks.org/minimum-insertions-to-form-a-palindrome-dp-28/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int findMinInsertions_recursion(string s, int l, int r){
    if (l > r)
        return INT_MAX;
    if (l == r)
        return 0;

    if (l == r-1)
        return (s[l] == s[r]) ? 0 : 1;

    return (s[l] == s[r]) ? findMinInsertions(s,l+1,r-1) : (1+ min(findMinInsertions(s,l,r-1),findMinInsertions(s,l+1,r)));
}

int findMinInsertions(string s, int l, int r){
	int n = r-l+1;
	vec2d(dp,int,n,n,0);

	int i,j;
	fr(gap,1,n-1){
		for(i=0, j=gap; j<n; ++i, ++j){
			if (s[i] == s[j])
				dp[i][j] = dp[i+1][j-1];
			else 
				dp[i][j] = min(dp[i][j-1], dp[i+1][j]) + 1;
		}
	}

	return dp[0][n-1];
}

int main(){
	string s;
	cin >> s;

	cout << "Recursion:" << endl;
	cout << findMinInsertions_recursion(s,0,s.length()-1) << endl;
	cout << endl;
	cout << "DP:" << endl;
	cout << findMinInsertions(s,0,s.length()-1) << endl;
	return 0;
}