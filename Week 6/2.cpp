#include <bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<vector<int>> &g) {
    vector<int> color(V, -1);
    queue<int> q;
 for (int j = 0; j < V; j++) {
    if (color[j] == -1) {
            color[j] = 0;
            q.push(j);

         while (!q.empty()) {
            int node = q.front();
                q.pop();

             for (int it : g[node]) {
                 if (color[it] == -1) {
                        color[it] = 1 - color[node];
                        q.push(it);
                     }
                else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
int main(){
        int V =4;

        vector<vector<int>> g(V);
        g[0]={1,2};
        g[1]={0};
        g[2]={0,3};
        g[3]={2};
        if (isBipartite(V, g))
        cout << "Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;

}
