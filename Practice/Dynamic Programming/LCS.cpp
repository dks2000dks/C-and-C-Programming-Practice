#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int LCS(string s1, string s2){
    int n = s1.length();
    int m = s2.length();

    vec2d(dp,int,n+1,m+1,0);

    fr(i,0,n){
        fr(j,0,m){
            if (i==0 || j==0)
                dp[i][j] = 0;
            else if (s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1;
        cin >> s2;

        cout << LCS(s1,s2) << endl;
    }
}