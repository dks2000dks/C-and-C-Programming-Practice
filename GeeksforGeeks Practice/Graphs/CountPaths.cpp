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

    int AllPathsUntil(int u,int d,bool visited[],int paths[],int path_index){
        int Count = 0;
        visited[u] = true;
        paths[path_index] = u;
        path_index++;

        if (u==d)
            Count++;
        else{
            for(auto it = adj[u].begin(); it != adj[u].end(); it++){
                if (!visited[*it])
                    Count += AllPathsUntil(*it, d, visited, paths, path_index);
            }
        }
        
        path_index--;
        visited[u] = false;

        return Count;
    }

    int CountPaths(int s, int d){
        
        bool visited[V] = {false};
        int paths[V];
        int path_index = 0;

        return AllPathsUntil(s,d,visited,paths,path_index);
    }
};

int main(){
    int T;
    cin >> T;

    while(T--){
        int V,E;
        cin >> V >> E;
        Graph g(V);

        while(E--){
            int a,b;
            cin >> a >> b;
            g.addEdge(a,b);
        }

        int s,d;
        cin >> s >> d;

        cout << g.CountPaths(s,d) << endl;
    }
}