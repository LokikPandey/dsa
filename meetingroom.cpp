#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0];
    });

    int ans = 1;
    int end = v[0][1];

    for(int i = 1; i < n; i++)
    {
        if(v[i][0] >= end)
        {
            ans++;
            end = v[i][1];
        }
        else
        {
            end = min(end, v[i][1]);
        }
    }

    cout << ans;
    return 0;
    
}