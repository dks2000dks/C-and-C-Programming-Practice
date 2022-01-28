#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void Merge(vector<int> &v, int l, int m, int r, int maxnum){
    int i = l;
    int j = m+1;
    int k = l;

    while (i <= m && j <= r) { 
        if (v[i] % maxnum <= v[j] % maxnum) { 
            v[k] = v[k] + (v[i] % maxnum) * maxnum; 
            k++; 
            i++; 
        } 
        else { 
            v[k] = v[k] + (v[j] % maxnum) * maxnum; 
            k++; 
            j++; 
        } 
    } 
    while (i <= m) { 
        v[k] = v[k] + (v[i] % maxnum) * maxnum; 
        k++; 
        i++; 
    } 
    while (j <= r) { 
        v[k] = v[k] + (v[j] % maxnum) * maxnum; 
        k++; 
        j++; 
    }

    for (int i = l; i <= r; i++) 
        v[i] = v[i] / maxnum;
}

void MergeSort(vector<int> &v, int l, int r, int maxnum){
    if (l<r){
        int m = (l+r)/2;
        MergeSort(v,l,m,maxnum);
        MergeSort(v,m+1,r,maxnum);

        Merge(v,l,m,r,maxnum);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vec1d(v,int,n,0);
        fr(i,0,n-1) cin >> v[i];

        int maxnum = *max_element(v.begin(),v.end()) + 1;
        MergeSort(v,0,n-1,maxnum);

        fr(i,0,n-1) cout << v[i] << " ";
        cout << endl;
    }
}
