#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int u, v, w;
};

void bellmanFord(int V, vector<Edge> &edges, int src){
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[src] = 0;

    // Relax edges
    for(int i=0;i<V-1;i++){
        for(auto e : edges){
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]){
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
            }
        }
    }

    // Print result
    for(int i=0;i<V;i++){
        cout << "Path to " << i << ": ";
        int j = i;
        while(j != -1){
            cout << j << " ";
            j = parent[j];
        }
        cout << " Distance: " << dist[i] << endl;
    }
}