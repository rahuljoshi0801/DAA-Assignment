/*l. Assume that a project of road construction to connect some
cities is given to your friend. Map of these cities and roads which will
connect them (after construction) is provided to him in the form of a
graph. Certain amount of rupees is associated with construction of each
road. Your friend has to calculate the minimum budget required for this
project. The budget should be designed in such a way that the cost of
connecting the cities should be minimum and number of roads required
to connect all the cities should be minimum (if there are N cities then
only N-1 roads need to be constructed). He asks you for help. Now, you
have to help your friend by designing an algorithm which will find
minimum cost required to connect these cities.

#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<pair<int,int>>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(V, 0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty())
    {
        auto it =pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(visited[node]==1) continue;
        //add it to mst
        visited[node] = 1;
        sum += wt;

        for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(visited[adjNode]==0){
                pq.push({adjWt, adjNode});

            }
        }
    }

    return sum; 

}
int main()
{
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i = 0; i < E; i++){
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
        

        

    cout << spanningTree(V, adj) << endl;
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int Prim(unordered_map<string , vector<pair<string ,
    int>>> &mp,unordered_map<string,int> &v){
        //max heap
        priority_queue<pair<int,pair<string,string>>,
        vector <pair<int,pair<string,string>>>,
        greater<pair<int,pair<string,string>>>> pq;
        
        string start  = mp.begin()->first;
        vector<pair<string,string>> mst;
        pq.push({0,{start,"-1"}});
        int sum =0;
        
        while(!pq.empty()){
            auto a = pq.top();
            pq.pop();
            // set weight, current node, parent node
            int wt =a.first;
            string cn =a.second.first;
            string parent = a.second.second;
            // if already visited 
            if(v.find(cn) != v.end() && v[cn]) continue;

            v[cn]=1;
            sum+=wt;

            if(parent != "-1"){
                mst.push_back({parent,cn});
            }

            for(auto i : mp[cn]){    
                if(!v[i.first]){
                    pq.push({i.second,{i.first,cn}});
                }
            }  
        }
        cout<< "Edges of mst"<<"\n";
        for(auto &e:mst){
            cout<< e.first<<"-"<<e.second<<"\n";
        }
        return sum;

    }
int main(){
    unordered_map<string , vector<pair<string ,int>>> mp;

    unordered_map<string,int> v;

    int n;
    cin>> n;
    for ( int i=0;i<n;i++){
        string u , vtx;
        int wt;
        cin>> u >>vtx >>wt;

        mp[u].push_back({vtx,wt});
        mp[vtx].push_back({u,wt});

    }

    int sum = Prim(mp,v);
    cout << "Sum is : "<< sum;
    return 0;
    
}