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
