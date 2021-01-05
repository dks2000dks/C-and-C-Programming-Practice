#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

int gcd(int a, int b) {
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 

    if (a == b) 
        return a; 

    if (a > b) 
        return gcd(a%b, b); 

    return gcd(a, b%a); 
} 

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
}