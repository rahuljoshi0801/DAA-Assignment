#include <bits/stdc++.h>
using namespace std;

int shortestPathKEdges(vector<vector<int>> &graph, int V, int src, int dest, int K){
    vector<vector<int>> dp(K+1, vector<int>(V, INT_MAX));

    dp[0][src] = 0;

    for(int i=1;i<=K;i++){
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                if(graph[u][v] != 0 && dp[i-1][u] != INT_MAX){
                    dp[i][v] = min(dp[i][v], dp[i-1][u] + graph[u][v]);
                }
            }
        }
    }

    return dp[K][dest];
}

int main(){
    int V = 4;
    vector<vector<int>> graph = {
        {0,1,0,3},
        {0,0,0,7},
        {0,0,0,6},
        {0,0,0,0}
    };

    int src = 0, dest = 3, K = 2;

    int ans = shortestPathKEdges(graph, V, src, dest, K);

    if(ans == INT_MAX)
        cout << "No path of length " << K << endl;
    else
        cout << "Shortest path weight: " << ans << endl;
}