#include<bits/stdc++.h>
using namespace std;



vector<int>  nextperm(vector<int> arr,int n)
{
    int ind=-1;
    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {

        reverse(arr.begin(),arr.end());
        return arr;
    }

    for(int i=ind+1;i<n;i++)
    {
        if(arr[i]>arr[ind])
        {
            swap(arr[i],arr[ind]);
            break;
        }
    }
    reverse(arr+ind+1,arr+n);

}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   vector<int> ans= nextperm(arr,n);
   for(auto i:ans) cout<<i<<" ";
    return 0;
}