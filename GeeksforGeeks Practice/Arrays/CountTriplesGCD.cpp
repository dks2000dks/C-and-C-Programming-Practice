#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

long Compute(vector<long> v, long r) {
    unordered_map<long,long> left,right;
    int n = v.size();
    long count = 0;

    for(int i=0;i<n;i++){
        right[v[i]]++;
    }

    long x=0, y=0;
    for(int i=0;i<n;i++){
        x=0, y=0;
        if (v[i]%r == 0)
            x = left[v[i]/r];
        
        // Decrease before Mutiplying
        right[v[i]]--;
        y = right[v[i] * r];

        count += (x*y);
        left[v[i]]++;
    }
    return count;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long r;
        cin >> n >> r;
        vec1d(v,long,n,0);
        fr(i,0,n-1) cin >> v[i];
        cout << Compute(v,r) << endl;
    }
}

