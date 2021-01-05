#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int PrimeSieve(int n){
    vec1d(prime,bool,n+1,true);

    for(int p=2; p*p <= n; p++){
        if (prime[p] == true){
            for(int i=p*p; i<=n; i+=p)
                prime[i] = false;
        }
    }

    int count = 0;
    fr(p,2,n){
        if (prime[p])
            count++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << PrimeSieve(n) << endl;
    }
}