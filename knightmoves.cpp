#include<bits/stdc++.h>
using namespace std;



bool fun(int c,int i,int j,vector<vector<int>> &g,int n)
{
    if(i<0 or i>=n or j<0 or j>=n or g[i][j]!=c) return false;
    if(g[i][j]==n*n-1) return true;

    int dx[]={-2,1,-2,1,2,-1,2,-1};
    int dy[]={-1,-2,1,2,-1,-2,1,2};

    for(int k=0;k<8;k++)
    {
        int nr=i+dx[k];
        int nc=j+dy[k];

        if(fun(c+1,nr,nc,g,n)) return true;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> g;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>g[i][j];
        }
    }

    return fun(0,0,0,g,n);
    return 0;
}