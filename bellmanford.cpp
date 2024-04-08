#include<bits/stdc++.h>
using namespace std;    

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++)
        {
            for(auto e:edges)
            {
                int wt=e[2];
                int v=e[1];
                int u=e[0];
                
                if(dist[u]+wt<dist[v])
                {
                    dist[v]=dist[u]+wt;
                }
            }
        }
        
        bool cycle=false;
        
        for(int i=0;i<V-1;i++)
        {
            for(auto e:edges)
            {
                int wt=e[2];
                int v=e[1];
                int u=e[0];
                
                if(dist[u]+wt<dist[v])
                {
                    cycle=true;
                    break;
                }
            }
        }
        if(cycle) return {-1};
        else return dist;
    }

int main()
{
    int V;
    cin>>V;

    vector<vector<int>> edges;

    for(int i=0;i<V;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<int> dist=bellman_ford(V,edges,0);
    return 0;
}