#include <bits/stdc++.h>
using namespace std;

class Edge{
    public: 
        int u, v, w;
        Edge() {}
        Edge(int u, int v, int w){
            this->u = u;
            this->v = v;
            this->w = w;
        }
};

int n, m;
vector <Edge> edgeList;
int dist[100];
int parent[100];

void bellmanFord(int source){
    for(int i = 0; i < n; i++){
        dist[i] = INT_MAX;
    }
    dist[source] = 0;
    parent[source] = -1;
    for(int i = 0; i < n-1; i++){
        for(Edge edge: edgeList){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if(dist[v] > dist[u]+ w){
                dist[v] = dist[u]+ w;
                parent[v] = u;
            }
        }
    }
    for(Edge edge: edgeList){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if(dist[v] > dist[u] + w){
                cout << "Negative cycle exits\n";
            }
    }
}

int main(){

    cin >>n >> m;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edgeList.push_back(Edge(u, v, w));
    }
    int source;
    cin >> source;
    bellmanFord(source);
    
    return 0;
}

// 5 10
// 0 1 10
// 0 3 5
// 1 2 1
// 1 3 2
// 2 4 4
// 3 1 -3
// 3 2 9
// 3 4 2
// 4 0 -7
// 4 2 6

// 1