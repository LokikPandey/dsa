#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int> &arr,int n)
{
    int a=*max_element(arr.begin(),arr.end());
    vector<int> count(a,0);

    for(int i=0;i<n;i++)
    {
        count[arr[i]]++;
    }

    for(int i=1;i<a;i++)
    {
        count[i]+=count[i-1];
    }

    vector<int> ans(n,0);
    for(int i=n-1;i>=0;i--)
    {
        ans[--count[arr[i]]]=arr[i];
    }

    arr=ans;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    count_sort(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}