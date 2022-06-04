#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    vector<int> edges[n+1],to[n+1];
    int d[n+1],from[n+1],ans[n+1];
    for (int i=1;i<=n;++i)
    {
        d[i]=n;
        to[i].clear();
        edges[i].clear();
    }
    while (m--)
    {
        cin>>x>>y;
        edges[x].push_back(y);
    }
    queue<int> q;
    q.push(1);
    d[1]=0;
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : edges[x])
            if (d[i]>d[x]+1)
            {
                d[i]=d[x]+1;
                q.push(i);
            }
    }
    for (int i=1;i<=n;++i)
    {
        ans[i]=d[i];
        from[i]=0;
        for (int j : edges[i])
        {
            ans[i]=min(ans[i],d[j]);
            if (d[i]<d[j])
            {
                ++from[i];
                to[j].push_back(i);
            }
        }
    }
    vector<int> v;
    for (int i=1;i<=n;++i)
        if (from[i]==0)
            v.push_back(i);
    while (!v.empty())
    {
        x=v.back();
        v.pop_back();
        for (int i : to[x])
        {
            ans[i]=min(ans[i],ans[x]);
            if (--from[i]==0)
                v.push_back(i);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}