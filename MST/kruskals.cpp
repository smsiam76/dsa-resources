#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};
int n,e;
Edge EdgeList[100];

int parent[100];

vector <Edge> tree;

bool comp(Edge e1, Edge e2){
    return e1.w < e2.w;
}

int kuruskal(){
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }
    sort(EdgeList, EdgeList+e, comp);

    int totalCost = 0;
    for(int i = 0; i < e; i++){
        int u =EdgeList[i].u;
        int v =EdgeList[i].v;
        int w =EdgeList[i].w;

        if(parent[u] != parent[v]){
            totalCost += w;

            int temp = parent[v];
            tree.push_back(EdgeList[i]);
            for(int i = 0; i < n; i++){
                if(parent[i] == temp)
                    parent[i] = parent[u];
            }
        }
    }
    return totalCost;

}


int main(){

    cin >> n >> e;

    for(int i = 0; i < e; i++){
        int u, v, w;
        cin >> u >> v >> w;

        EdgeList[i].u = u;
        EdgeList[i].v = v;
        EdgeList[i].w = w;
    }

    // for(int i = 0; i < e; i ++){
    //     cout << EdgeList[i].u <<" " << EdgeList[i].v << endl;
    // }

    cout << kuruskal() << endl;

    for(Edge e: tree){
        cout << e.u << " " << e.v << " " << e.w  << endl;
    }
    return 0;
}

// 4 6
// 0 1 2
// 0 2 3
// 0 3 2
// 1 2 1
// 1 3 4
// 2 3 4


