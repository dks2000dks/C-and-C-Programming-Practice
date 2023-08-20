// Source: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/?ref=lbp

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
};

int main(){
	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(0, 2); 
	g.addEdge(1, 2); 
	g.addEdge(2, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 3);

	g.BFS(2);
}