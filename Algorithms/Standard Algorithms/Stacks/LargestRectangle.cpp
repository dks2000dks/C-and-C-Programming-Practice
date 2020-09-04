#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int maxHist(vector<int> &a) {
        int m = a.size(), ans=0;
        stack<int> s;
        for(int j=0; j<m; j++) {
            if(s.empty() || a[s.top()]<a[j]) s.push(j);
            else {
                while(!s.empty() && a[s.top()]>=a[j]) {
                    int ht= a[s.top()]; s.pop();
                    if(!s.empty()) ans= max(ans, (j-s.top()-1)*ht);
                    else ans= max(ans, j*ht);
                }
                s.push(j);
            }
        }
        while(!s.empty()) {
            int ht= a[s.top()]; s.pop();
            if(!s.empty()) ans= max(ans, (m-s.top()-1)*ht);
            else ans= max(ans, m*ht);
        }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];
        cout << maxHist(v) << endl;        
    }
}