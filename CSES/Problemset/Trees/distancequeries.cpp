#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=2e5+1;
int t,up[MAXN][19],height[MAXN],tin[MAXN],tout[MAXN];
vector<int> edges[MAXN];

void dfs(int c, int p, int h)
{
    ++t;
    tin[c]=t;
    height[c]=h;
    up[c][0]=p;
    for (int i=1;i<19;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1);
    ++t;
    tout[c]=t;
}

bool isParent(int p, int c)
{
    if (tin[p]<=tin[c]&&tout[c]<=tout[p])
        return 1;
    return 0;
}

int lca(int u, int v)
{
    if (isParent(u,v))
        return u;
    if (isParent(v,u))
        return v;
    for (int i=18;i>=0;--i)
        if (!isParent(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,u,v;
    cin>>n>>q;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,0);
    tout[0]=t+1;
    while (q--)
    {
        cin>>u>>v;
        cout<<height[u]+height[v]-2*height[lca(u,v)]<<"\n";
    }
    return 0;
}