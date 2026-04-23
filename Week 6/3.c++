#include<bits/stdc++.h>
using namespace std;
bool detected(int node, vector<vector<int>> &g,vector<int> &visited){
    visited[node]=1;
    queue<pair<int,int>> q;
    q.push({node,-1});
    while(!q.empty()){
        int curr=q.front().first;
        int parent=q.front().second;
        q.pop(); 
        for(auto it :g[curr]){
            if (!visited[it]){
                visited[it]=1;
                q.push({it,curr});
            }
            else if(it!=parent){
                return true;
            }
        }
    }
    return false;
}

void cycle ( vector<vector<int>> &g ){
    vector<int> visited(g.size(),0);
    for(int i=0;i<g.size();i++){
        if(!visited[i]){
            if(detected(i,g,visited)){
                cout<<"cycle detected\n";
                return;
            }
        }
    }
    cout<<"no cycle detected\n";
}
int main(){
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<vector<int>> g(V);

    for(int i = 0; i < E; i++){
        int u, v;
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    cycle(g);
    return 0;
}