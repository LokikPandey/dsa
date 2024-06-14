#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr={0,2,2,1,2,1,0,0};
    
    int l=0,m=0,h=7;
    
    while(m<=h)
    {k
        switch(arr[m])
        {
            case 0 :
            {
                swap(arr[m++],arr[l++]);
            }
            break;
            
            case 1:
            {
                m++;
            }
            break;
            
            case 2:
            swap(arr[m],arr[h--]);
            break;
        }
    }
    
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}