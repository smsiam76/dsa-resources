#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int v, e;

vector <pair<int, int>> adjList[100];
int key[100];
int parent[100];
bool tree[100];

int primAlgo(){
    for(int i = 0; i < v; i++){
        key[i] = INT_MAX;
        tree[i] = false;
    }

    int root = 0;
    key[root] = 0;
    parent[root] = -1;

    priority_queue<pii, vector<pii>, greater<pii>> pq; //min heap

    pq.push({key[root], root});

    while(!pq.empty()){
        pii p = pq.top();
        int u = p.second;
        pq.pop();
        if(tree[u]) continue;

        tree[u] = true;

        for(pii q: adjList[u]){
            int v = q.first;
            int w =  q.second;
            
            if(not tree[v] and w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int total_weight = 0;

    for(int k:key) 
        total_weight +=k;

    return total_weight;



}


// vector <data type> name 
int main(){

    cin >> v >> e;

    for(int i = 0; i < e; i++){
        int a, b, w;
        cin >> a >> b >> w;
        adjList[a].push_back({b, w});
        adjList[b].push_back({a, w});
    }

    // print
    // for(int i = 0; i < v; i++){
    //   cout << "Node" << i << ": ";
    //   for(auto it: adjList[i]){
    //     cout << "(" << it.first << ". " << it.second << ") ";
    //   }
    //   cout << endl;
    // }

    cout << primAlgo() << endl;


    return 0;
}



// 5 7
// 0 1 2
// 1 2 7
// 1 4 3
// 1 3 9
// 0 2 1
// 2 3 5
// 4 3 8


// 6 9
// 4 3 4 
// 4 1 2
// 4 2 7
// 4 5 8
// 1 0 2
// 1 3 4
// 1 2 6
// 0 3 7
// 2 5 6