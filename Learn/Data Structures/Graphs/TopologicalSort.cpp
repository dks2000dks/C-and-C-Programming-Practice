#include <iostream>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits.h>
#include <string>
#include <math.h> 
#include <float.h>
#include <bitset>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

class Graph{
    int V;
    list<int> *adj;

public:

    Graph(int V){
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int v, int w){
        adj[v].push_back(w);
    }

    void TopologicalSortUntil(int v, bool visited[], stack<int> &s){
        visited[v] = true;

        for(auto it=adj[v].begin(); it!=adj[v].end(); ++it){
            if (!visited[*it])
                TopologicalSortUntil(*it,visited,s);
        }
        s.push(v);
    }

    void TopologicalSort(){
        stack<int> s;

        bool *visited = new bool[V];
        fr(i,0,V-1)
            visited[i] = false;

        fr(i,0,V-1){
            if (visited[i] == false)
                TopologicalSortUntil(i,visited,s);
        }

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
};

int main(){
    Graph g(6);

    g.addEdge(5,2);
    g.addEdge(5,0); 
    g.addEdge(4,0); 
    g.addEdge(4,1); 
    g.addEdge(2,3); 
    g.addEdge(3,1);

    g.TopologicalSort();
}