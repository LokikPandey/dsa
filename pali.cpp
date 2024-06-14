#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int k;
    cin>>k;
    int i=0,j=n-1;
    while(i<j)
    {
        if(s[i]!=s[j]) k--;
        if(k<0) break;
        i++;
        j--;
    }
    if(k<0) cout<<"false";
    else cout<<"true";
    return 0;
}