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
#define br(i, a, b) for (int i=a; i>=b; i--)
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

    // BFS
    void BFS(int s){
        bool *visited = new bool[V];

        fr(i,0,V-1){
            visited[i] = false;
        }

        list<int> queue;

        visited[s] = true;
        queue.push_back(s);

        while(!queue.empty()){
            s = queue.front();
            cout << s << " ";
            queue.pop_front();

            for(auto it = adj[s].begin(); it!= adj[s].end(); it++){
                if (!visited[*it]){
                    visited[*it] = true;
                    queue.push_back(*it);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFSUntil(int v, bool visited[]){
        visited[v] = true;
        cout << v << " ";

        for(auto it = adj[v].begin(); it != adj[v].end(); it++){
            if (!visited[*it])
                DFSUntil(*it, visited);
        }
    }

    void DFS(int v){
        bool *visited = new bool[V];

        fr(i,0,V-1){
            visited[i] = false;
        }

        DFSUntil(v, visited);
        cout << endl;
    }

    // For Disconnected Graph
    void DFS_DisConnected(int v){
        bool *visited = new bool[V];

        fr(i,0,V-1){
            visited[i] = false;
        }

        
        fr(i,0,V-1){
            if (visited[i] == false)
                DFSUntil(v, visited);
        }
        cout << endl;
    }
};