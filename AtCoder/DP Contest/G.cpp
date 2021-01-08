#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1;
vector<int> from[mn];
int to[mn],dp[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,ans=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        from[x].push_back(y);
        ++to[y];
    }
    stack<int> s;
    for (int i=1;i<=n;++i)
        if (to[i]==0)
            s.push(i);
    while (!s.empty())
    {
        x=s.top();s.pop();
        ans=max(ans,dp[x]);
        for (int i : from[x])
        {
            if (--to[i]==0)
                s.push(i);
            dp[i]=max(dp[i],dp[x]+1);
        }
    }
    cout<<ans;
    return 0;
}