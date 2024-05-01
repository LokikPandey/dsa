#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a=54593675,b=3923645;
    a^=b;
    b^=a;
    a^=b;
    cout<<a<<" "<<b;
    return 0;
}