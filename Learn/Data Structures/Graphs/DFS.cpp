// Source: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/?ref=lbp

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

int main(){
	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3);

	g.DFS(2);
}