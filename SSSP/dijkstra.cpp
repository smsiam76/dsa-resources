#include<bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int n, m; // Number of nodes and edges

vector<pii> adj[100];
int dist[100];
int parent[100];

void dijkstra(int source) {

    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        parent[i] = -1;
    }

    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, source});

    while(!pq.empty()) {

        pii temp = pq.top();
        pq.pop();

        int d = temp.first;
        int u = temp.second;

        // Skip outdated entry
        if(d > dist[u])
            continue;

        for(pii p : adj[u]) {

            int v = p.first;
            int w = p.second;

            // Relaxation
            if(dist[v] > dist[u] + w) {

                dist[v] = dist[u] + w;
                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }
}

void printPath(int source, int destination) {

    if(destination == source) {
        cout << source;
        return;
    }

    printPath(source, parent[destination]);
    cout << " => " << destination;
}

int main() {

    cin >> n >> m;

    for(int i = 0; i < m; i++) {

        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }

    int source, destination;
    cin >> source >> destination;

    dijkstra(source);

    cout << "\nShortest Distances:\n";

    for(int i = 0; i < n; i++) {

        cout << "Distance from " << source << " to " << i << " = ";

        if(dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    cout << "\nShortest Path from " << source << " to "<< destination<< ":\n";

    if(dist[destination] == INT_MAX) {
        cout << "No Path Exists\n";
    }
    else {
        printPath(source, destination);
        cout << endl;
        cout << "Total Cost = " << dist[destination] << endl;
    }

    return 0;
}

// 5 10
// 0 1 10
// 0 3 5
// 1 2 1
// 1 3 2
// 2 4 4
// 3 1 3
// 3 2 9
// 3 4 2
// 4 0 7
// 4 2 6