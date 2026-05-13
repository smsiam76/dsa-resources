#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int v, e, f;

vector<pair<int, int>> adjList[100];

int parent[100];
int key[100];
bool tree[100];

bool prims(){
    for(int i = 0; i < v; i++){
        key[i] = INT_MAX;
        tree[i] = false;
        parent[i] = -1;
    }
    int root = 0;
    key[root] = 0;

    priority_queue <pii, vector<pii>, greater<pii>> pq;

    pq.push({key[root], root});

    while(!pq.empty()){
        pii p = pq.top();
        int u = p.second;

        pq.pop();
        if(tree[u]) continue;
        tree[u] = true;

        for(pii q: adjList[u]){
            int v = q.first;
            int w = q.second;

            while(!tree[v] && w < key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v],v});
            }
        }

    }

    int totalWeight = 0;
    for(int k: key){
        totalWeight += k;
    }
    
    if(totalWeight < f) return true;
    return false;
}


int main(){

    cin >> v >> e;
    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }
    cin >> f;
    
    int result = prims();
    if(result == 1) cout << "YES";
    else
    cout << "NO" << endl;
   
    return 0;
}