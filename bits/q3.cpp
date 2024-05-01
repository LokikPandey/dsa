#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=0;i<32;i++)
    {
        if((n&(1<<i))!=0) count++;
    }
    if(count==1) cout<<"power of two";
    else cout<<"not power of two";
    // if((n&(1))!=0) cout<<"no";
    // else cout<<"yes";
}