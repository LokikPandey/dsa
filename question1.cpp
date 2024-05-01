#include<bits/stdc++.h>
using namespace std;

int arr[1000],seg[4000];

void build(int i,int low,int high)
{
    if(high==low) seg[i]=arr[low];
    else{
        int mid=(high+low)/2;
        build(2*i+1,low,mid);
        build(2*i+2,mid+1,high);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
}

int query(int i,int l,int r,int low,int high)
{
    if(l>=low and r<=high) return seg[i];
    else if(r<low or l>high) return 0;
    else
    {
        int mid=(low+high)/2;
        return query(2*i+1,l,r,low,mid)+query(2*i+2,l,r,mid+1,high);
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n-1);
    // cout<<query(0,0,3,0,n-1);
    return 0;
}
