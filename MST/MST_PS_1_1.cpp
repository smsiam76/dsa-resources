#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int v, e;
vector<pair<int, int>> adjList[100];

int key[100];
int parent[100];
int tree[100];

int prims(){
    for(int i = 1; i <= v; i++){
        key[i] = INT_MIN;
        tree[i] = false;
        parent[i] = -1;
    }
    
    int root = 1;
    key[root] = 0;

    // priority_queue <pii, vector<pii>, greater<pii>> pq; //min heap
    priority_queue <pii> pq; //max heap

    pq.push({key[root], root});

    while(!pq.empty()){
        pii p = pq.top();
        int u = p.second;
        pq.pop();

        if(tree[u]) continue;
        tree[u] = true;

        for(pii p: adjList[u]){
            int v = p.first;
            int w = p.second;

            while(not tree[v] and w > key[v]){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }
    int total_w = 0;
    for(int k: key){
        total_w += k;
    }
    return total_w;
}

int main(){
    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;

        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }
    int primsAlgo = prims();
    
    cout << "parent values" << endl;
    // parent values
    for(int i = 1; i <= v; i++){
       cout << parent[i] << " ";
    }

    cout << endl << "key values" << endl;
    // key values
    for(int i = 1; i <= v; i++){
        cout << key[i] << " ";
    }
    cout << endl << "The weight of the maximum spanning tree is " << primsAlgo << endl;

    return 0;
}

// 6 8
// 1 2 10
// 2 4 20
// 4 5 5
// 5 6 5
// 6 3 10
// 1 3 10
// 1 5 10
// 3 5 5