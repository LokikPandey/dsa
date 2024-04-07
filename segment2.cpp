#include<bits/stdc++.h>
using namespace std;
int arr[100005],seg[4*100005];

void build(int i,int low,int high)
{
    if(low==high)
    {
        seg[i]=arr[low];
        return;
    }
    int mid=(low+high)/2;

    build(2*i+1,low,mid);
    build(2*i+2,mid+1,high);

    seg[i]=max(seg[2*i+1],seg[2*i+2]);
}

int query(int i,int low,int high,int l,int r)
{
    if(l>=low and high<=r) return seg[i];
    else if(high<l or low>r) return INT_MIN;
    else{
        int mid=(low+high)/2;
        int left=query(2*i+1,low,mid,l,r);
        int right=query(2*i+2,mid+1,high,l,r);
        return max(left,right);
    }
}
void newd(int data,int index,int n)
{
    // int n=arr.length();
    arr[index]=data;
    build(0,0,n-1);
}

int main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    int data,ind;
    for(int i=0;i<4*n;i++) cout<<seg[i]<<" ";
    cout<<"Enter new data into the tree:";
    cin>>data>>ind;
    newd(data,ind,n);

    for(int i=0;i<4*n;i++) cout<<seg[i]<<" ";

    // int q;
    // cin>>q;
    // while(q--)
    // {
    //     int l,r;
    //     cin>>l>>r;
    //     int ans=query(0,0,n-1,l,r);
    //     cout<<ans<<" ";
    }
