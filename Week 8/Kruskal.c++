#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// Find with path compression
int findParent(int x) {
    if (parent[x] != x)
        parent[x] = findParent(parent[x]);
    return parent[x];
}

// Kruskal function
int kruskalMST(int V, vector<pair<int, pair<int,int>>> &edges) {
    
    // Sort edges (weight first)
    sort(edges.begin(), edges.end());

    // Initialize parent
    parent.resize(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int totalCost = 0;
    int edgeCount = 0;

    for (auto &edge : edges) {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv) {
            parent[pv] = pu;   // union
            totalCost += w;
            edgeCount++;

            if (edgeCount == V - 1)
                break;
        }
    }

    return totalCost;
}

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter number of edges: ";
    cin >> E;

    vector<pair<int, pair<int,int>>> edges;

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }

    int result = kruskalMST(V, edges);

    cout << "Minimum Cost to Connect Graph: " << result << endl;

    return 0;
}