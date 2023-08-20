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
    int *rank, *parent, n;
public:
    DisjSet(int n){
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet(){
        fr(i,0,n-1){
            parent[i] = i;
        }
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

    void Union(int x, int y){
        int xpar = FindParent(x);
        int ypar = FindParent(y);

        if (xpar == ypar)
            return;
        
        else if (rank[xpar] < rank[ypar]){
            parent[xpar] = ypar;
        }

        else if (rank[xpar] > rank[ypar]){
            parent[ypar] = xpar;
        }

        else{
            parent[ypar] = xpar;
            rank[xpar] = rank[xpar] + 1;
        }       
    }
};

int main(){
    DisjSet obj(12);
    obj.Union(2,10);
    obj.Union(7,5);
    obj.Union(6,1);
    obj.Union(3,4);
    obj.Union(5,11);
    obj.Union(7,8);
    obj.Union(7,3);
    obj.Union(12,2);
    obj.Union(9,6);

    cout << obj.FindParent(6) << endl;
    cout << obj.FindParent(3) << endl;
    cout << obj.FindParent(11) << endl;
    cout << obj.FindParent(9) << endl;

    if (obj.FindParent(4) == obj.FindParent(0))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;    
}