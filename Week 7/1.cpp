#include <bits/stdc++.h>
using namespace std;

void dijkstra(int V, vector<vector<pair<int,int>>> &adj, int src){
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;

            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    // Print path + distance
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