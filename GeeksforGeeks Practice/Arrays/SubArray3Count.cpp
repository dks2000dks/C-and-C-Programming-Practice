#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int Compute(vector<int> &v, int n){
    map<int,int> mp;
    int o = 0;

    fr(i,0,n-2){
        fr(j,i+1,n-1){
            if (v[i] > v[j]){
                o += mp[i];
                mp[j]++;
            }
        }
    }
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];
        cout << Compute(v,n) << endl;
    }
}
