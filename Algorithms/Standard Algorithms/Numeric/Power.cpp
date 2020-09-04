#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

ll Power(ll n, ll k){
    ll o = 1;

    while(k){
        if (k%2 == 1){
            o = o*n;
            k--;
        }
        n = n*n;
        k = k/2;   
    }
    return o;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,k;
        cin >> n >> k;
        cout << Power(n,k) << endl;
    }
}