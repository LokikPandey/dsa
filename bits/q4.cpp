//find the number of set bits
//12-1100,13-1101

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<32;i++)
    {
        if ((n&(1<<i))!=0) count++;
    }
    cout<<count;
}
