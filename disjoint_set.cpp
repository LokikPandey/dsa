#include<bits/stdc++.h>
using namespace std;

class disjointSet{
    vector<int> rank,size,parent;
    public:
    disjointSet(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findpar(int node)
    {
        if(node==parent[node]) return node;
        else return parent[node]=findpar(parent[node]);
    }

    void unionbyrank(int u,int v)
    {
        int ult_u=findpar(u);
        int ult_v=findpar(v);

        if(ult_u==ult_v) return;
        if(rank[ult_u]<rank[ult_v]) parent[ult_u]=ult_v;
        else if(rank[ult_u]>rank[ult_v]) parent[ult_v]=ult_u;
        else
        {
            parent[ult_v]=ult_u;
            rank[ult_u]++;
        }
    }

    void unionbysize(int u,int v)
    {
        int ult_u=findpar(u);
        int ult_v=findpar(v);

        if(ult_u==ult_v) return;
        if(size[ult_u]<size[ult_v])
        {
            parent[ult_u]=ult_v;
            size[ult_v]+=size[ult_u];
        }
        else
        {
            parent[ult_v]=ult_u;
            size[ult_u]+=size[ult_v];
        }
    }

};

int main()
{
    disjointSet ds(7);
    ds.unionbysize(1,2);
    ds.unionbysize(2,3);
    ds.unionbysize(4,5);
    ds.unionbysize(6,7);
    ds.unionbysize(5,6);

    if(ds.findpar(3)==ds.findpar(4))
    {
        cout<<'same'<<endl;
    }
    else cout<<"not same";

    return 0;
}