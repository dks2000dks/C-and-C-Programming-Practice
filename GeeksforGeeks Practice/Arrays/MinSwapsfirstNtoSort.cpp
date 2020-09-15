#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int Compute(vector<int> &v, int n){
    int count = 0;
    int i = 0;

    while(i<n){
        while (v[i] != i+1){
            swap(v[i],v[v[i]-1]);
            count++;
        }
        i++;
    }
    return count;
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