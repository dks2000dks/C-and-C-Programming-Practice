#include<iostream>
#include<cmath>
#include <cassert>
#include<algorithm>
#include <cstdlib>
#include<vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include<string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class DisjSet{
    int *parent, n;
    long long int *rows;
public:
    DisjSet(int n){
        parent = new int[n];
        rows = new long long int[n];
        this->n = n;
        makeSet();
    }
    
    void makeSet(){
        fr(i,0,n-1){
            parent[i] = i;
        }
    }

    long long int InitialiseRows(){
        fr(i,0,n-1){
            cin >> (rows[i]);
        }
        return *max_element(rows+0,rows+n);
    }

    int FindParent(int x){
        if (parent[x] == x)
            return parent[x];
        else{
            int result = FindParent(parent[x]);
            parent[x] = result;
            return result;
        }
    }

    long long int MaxSizeUnion(int x, int y, int xpar, int ypar){

        if (xpar == ypar){
            return rows[xpar];
        }

        else if (rows[xpar] < rows[ypar]){
            rows[ypar] += rows[xpar];
			parent[xpar] = ypar;

            return rows[ypar];
        }

        else{
            rows[xpar] += rows[ypar];
			parent[ypar] = xpar;

            return rows[xpar];
        }
    }
};

int main(){
    int n,o;
    cin >> n >> o;

    DisjSet obj(n);
    long long int MaxElement = obj.InitialiseRows();

    fr(i,0,o-1){
        int t1,t2;
        cin >> t1 >> t2;
		int t1par = obj.FindParent(t1-1);
		int t2par = obj.FindParent(t2-1);
        long long int Element = obj.MaxSizeUnion(t1-1, t2-1, t1par, t2par);
        MaxElement = max(MaxElement, Element);
        cout << MaxElement << endl;
    }
}