#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int Totient(int N){
    int o = N;
    for(int i=2;i*i<=N;i++){
        if (N%i == 0)
            o = o - o/i;
        while(N%i == 0)
            N = N/i;
    }
    if (N>1)
        o = o - o/N
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << Totient(n) << endl;
    }
}