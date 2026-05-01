Ques. Assume that same road construction project is given to another person. 
The amount he will earn from this project is directly proportional to the budget of the project.
This person is greedy, so he decided to maximize the budget by constructing those roads who have highest construction cost.
Design an algorithm and implement it using a program to find the maximum budget required for the project.

Input Format:
The first line of input takes number of vertices in the graph.
Input will be the graph in the form of adjacency matrix or adjacency list.
Output Format:
Out will be maximum spanning weight.
Sample 1/0 Problem IlI:
Input: Output:
7 Maximum Spanning Weight: 59

#include <bits/stdc++.h>
using namespace std;
int findParent(int u,vector<int> &parent){
    if(parent[u] == u) return u;
    return parent[u] = findParent(parent[u],parent);
}
void Union(int u,int v,vector<int> &parent,vector<int> &rank){
    u = findParent(u,parent);
    v = findParent(v,parent);
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int Kruskal(int V, vector<vector<pair<int,int>>> &adj){
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<V;i++){
        for(auto it : adj[i]){
            int adjNode = it.first;
            int wt = it.second;
            edges.push_back({wt,{i,adjNode}});
        }
    }
    sort(edges.rbegin(),edges.rend());
    vector<int> parent(V);
    vector<int> rank(V,0);
    for(int i=0;i<V;i++){
        parent[i] = i;
    }
    int sum = 0;
    for(auto it : edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;
        if(findParent(u,parent) != findParent(v,parent)){
            Union(u,v,parent,rank);
            sum += wt;
        }
    }
    return sum;
}