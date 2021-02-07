#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1, mod = 1e9+7;
vector<int> from[mn];
int to[mn],dp[mn];

void add(int& a, int& b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    dp[1]=1;
    while (m--)
    {
        cin>>x>>y;
        from[x].push_back(y);
        ++to[y];
    }
    stack<int> s;
    for (int i=1;i<=n;++i)
        if (!to[i])
            s.push(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i : from[x])
        {
            add(dp[i],dp[x]);
            if (!--to[i])
                s.push(i);
        }
    }
    cout<<dp[n];
    return 0;
}