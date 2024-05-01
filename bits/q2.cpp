#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int i;cin>>i;
    // if(n&(1<<i)!=0) cout<<"true";
    // else cout<<"false";
    int m=n-1;
    cout<<(n&m);
    n=(1<<i)^n;//toggling bit in the number
    // cout<<n;
    return 0;
}