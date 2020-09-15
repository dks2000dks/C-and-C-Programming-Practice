#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

vector<int> Compute(string s){
    int l=0,r=0,k;
    int n = s.length();
    vec1d(Z,int,n,0);
    Z[0] = n;

    fr(i,1,n-1){
        if (i>r){
            l=r=i;

            while(r<n && s[r-l] == s[r])
                r++;
            Z[i] = r-l;
            r--;
        }
        else{
            k = i-l;

            if (Z[k] < r-i+1)
                Z[i] = Z[k];
            else{
                l = i;
                while(r<n && s[r-l] == s[r])
                    r++;
                Z[i] = r-l;
                r--;
            }
        }
    }
    return Z;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        vector<int> v = Compute(s);
        cout << accumulate(v.begin(),v.end(),0) << endl;
    }
}