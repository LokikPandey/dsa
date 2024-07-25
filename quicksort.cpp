#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

// 3 4 2 5 6 3

int partition(vector<int> &arr,int low,int high)
{
    int i=low-1;
    int pivot=arr[high];

    for(int j=low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }

    }

    swap(arr[i+1],arr[high]);
    return i+1;
}
void quicksort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main()
{
    vector<int> arr = {4,3,2,5,6,45,56546,456,333,9,0};
    int n=arr.size();
    quicksort(arr,0,n-1);

    for(auto i:arr) cout<<i<<" ";
    return 0;
}