#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+3,INF=1e9;
const ll BIG = 1e18;
vector<int> edges[mn];
bitset<mn> done;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n,x,t=0;
    cin>>n;
    ll dp[n+1],ans=-BIG,depthQ[n+1][2];
    int a[n+1],depth[n+1],depthRange[n+1][2],pt[n+1],v[n+1];
    for (int i=0;i<=n;++i)
    {
        edges[i].clear();
        done[i]=0;
        depthRange[i][0]=INF;
        depthRange[i][1]=-INF;
        depthQ[i][0]=-BIG;
        depthQ[i][1]=-BIG;
    }
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        edges[i].push_back(x);
        edges[x].push_back(i);
    }
    for (int i=2;i<=n;++i)
        cin>>a[i];
    depth[1]=0;
    dp[1]=0;
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        done[x]=1;
        v[++t]=x;
        for (int i : edges[x])
            if (!done[i])
            {
                q.push(i);
                depth[i]=depth[x]+1;
                depthRange[depth[i]][0]=min(depthRange[depth[i]][0],a[i]);
                depthRange[depth[i]][1]=max(depthRange[depth[i]][1],a[i]);
                pt[i]=x;
            }
    }
    depthQ[0][0]=-depthRange[1][0];
    depthQ[0][1]=depthRange[1][1];
    for (int i=2;i<=n;++i)
    {
        dp[v[i]]=max(dp[pt[v[i]]]+max(depthRange[depth[v[i]]][1]-a[v[i]],a[v[i]]-depthRange[depth[v[i]]][0]),max(depthQ[depth[v[i]]-1][0]+a[v[i]],depthQ[depth[v[i]]-1][1]-a[v[i]]));
        for (int j : edges[v[i]])
            if (j!=pt[v[i]])
            {
                depthQ[depth[v[i]]][0]=max(depthQ[depth[v[i]]][0],dp[v[i]]-a[j]);
                depthQ[depth[v[i]]][1]=max(depthQ[depth[v[i]]][1],dp[v[i]]+a[j]);
            }
        ans=max(ans,dp[v[i]]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}