#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int parent[100];
int rankArr[100];

void makeSet(int x){
    parent[x] = x;
    rankArr[x] = 0;
}

int findSet(int x){
    if(parent[x] != x)
        parent[x] = findSet(parent[x]); // path compression
    return parent[x];
}

void unionSet(int u, int v){
    int Ru = findSet(u);
    int Rv = findSet(v);

    if(Ru == Rv) return;

    if(rankArr[Ru] < rankArr[Rv]){
        parent[Ru] = Rv;
    }
    else if(rankArr[Ru] > rankArr[Rv]){
        parent[Rv] = Ru;
    }
    else{
        parent[Rv] = Ru;
        rankArr[Ru]++;
    }
}

int main(){
    int n = 4, m = 6;

    vector<Edge> edges = {
        {0,1,2},
        {0,2,3},
        {0,3,2},
        {1,2,1},
        {1,3,4},
        {2,3,4}
    };

    // Step 1: sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    // Step 2: initialize DSU
    for(int i = 0; i < n; i++){
        makeSet(i);
    }

    int mstCost = 0;
    vector<Edge> mstEdges;

    // Step 3: process edges
    for(auto e : edges){
        if(findSet(e.u) != findSet(e.v)){
            unionSet(e.u, e.v);
            mstCost += e.w;
            mstEdges.push_back(e);
        }
    }

    // Output
    cout << "MST Cost: " << mstCost << endl;
    cout << "Edges in MST:\n";
    for(auto e : mstEdges){
        cout << e.u << " - " << e.v << " : " << e.w << endl;
    }

    return 0;
}