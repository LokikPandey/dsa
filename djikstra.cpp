#include<bits/stdc++.h>
using namespace std;

vector<int> djikstra(int V,vector<vector<int>> adj[],int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int> dist(V,1e9);
    dist[S]=0;
    pq.push({0,S});
    while(!pq.empty())
    {
        int dis=pq.top().first;
        int node=pq.top().second;

        for(auto i:adj[node])
        {
            int adjnode=i[0];
            int weight=i[1];

            if(weight+dis<dist[adjnode])
            {
                dist[adjnode]=weight+dis;
                pq.push({dist[adjnode],adjnode});
            }
        }
    }
    return dist;
}

int main()
{
    int V,E;
    cin>>V>>E;
    vector<vector<int>> g[V];
    int i=0;
        while(i++<V){
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            g[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            g[v].push_back(t2);
        }   
    vector<int> ans;
    ans=djikstra(V,g,0);
    for(auto i:ans) cout<<i<<" ";
    return 0;
}