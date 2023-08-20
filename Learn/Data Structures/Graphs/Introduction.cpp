// Source: https://www.geeksforgeeks.org/introduction-to-graphs-data-structure-and-algorithm-tutorials/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define fr(i, a, b) for (int i=a; i<=b; i++)
#define vec1d(v,T,n,init) vector<T> v(n,init)
#define vec2d(v,T,n,m,init) vector<vector<T>> v(n, vector<T>(m,init))

void addEdge(vector<int> adj[], int u, int v){ 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
}

void printGraph(vector<int> adj[], int V){
	fr(v,0,V-1){
		cout << "Adjacency List of Vertex: " << v << endl;
		cout << v;
		for (auto x : adj[v]) 
		   cout << " -> " << x;
		cout << endl;
	}
}

int main(){
	int V = 5;

	// Creates Array of Vectors
	vector<int> adj[V];
	
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	
	printGraph(adj, V);
}