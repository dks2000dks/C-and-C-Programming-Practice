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

int minDistance(vector<int> distance, vector<bool> sptset){
    int min=INT_MAX;
    int min_Index;
    int V = sptset.size();

    fr(i,0,V-1){
        if (sptset[i] == false && distance[i] <= min){
            min = distance[i];
            min_Index = i;
        }
    }
    return min_Index;
}

vector<int> Dijksta(vector<vector<int>> Graph, int source){
    int V = Graph.size();
    vec1d(distance,int,V,INT_MAX);
    vec1d(sptset,bool,V,false);

    distance[source] = 0;

    fr(i,0,V-2){
        int u = minDistance(distance,sptset);
        sptset[u] = true;

        fr(v,0,V-1){
            if (u != v && !sptset[v] && Graph[u][v] && distance[u] + Graph[u][v] < distance[v])
                distance[v] = distance[u] + Graph[u][v];
        }
    }
    return distance;
}

int main(){
    int V;
    cin >> V;

    vec2d(Graph,int,V,V,0);
    int a,b,val;

    int e;
    cin >> e;

    while(e--){
        cin >> a >> b >> val;
        Graph[a][b] = val;
        Graph[b][a] = val;
    }

    int source = 0;
    vector<int> distances = Dijksta(Graph,source);

    fr(i,0,V-1)
        cout << i << " " << distances[i] << endl;
    cout << endl;
}