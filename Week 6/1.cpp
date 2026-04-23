#include <bits/stdc++.h>
using namespace std;
stack<int> s;
void dfs(int start, vector<vector<int>> &g, vector<int> &visited, int end) {
  s.push(start);
  while (!s.empty()) {
    int node = s.top();
    s.pop();
    if (visited[node])
      continue;
    visited[node] = 1;

    if (node == end) {
      cout << "Path Exists";
      return;
    }

    for (auto it : g[node]) {
      if (!visited[it])
        s.push(it);
    }
  }
  cout << "Path Does not Exists";
}
int main() {
  int V, E;
  cin >> V >> E;
  vector<vector<int>> g(V + 1);
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> visited(V + 1, 0);
  int start;
  cin >> start;
  int end;
  cin >> end;
  dfs(start, g, visited, end);

  return 0;
}
