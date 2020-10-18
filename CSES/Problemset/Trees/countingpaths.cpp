#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 2e5+7, lg = 18;
vector<int> edges[maxn];
int subTree[maxn],up[lg][maxn],tin[maxn],tout[maxn],t;

void dfs(int c, int p)
{
    up[0][c]=p;
    tin[c]=++t;
    for (int i=1;i<lg;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
    tout[c]=++t;
}

void dfs1(int c, int p)
{
    for (int i : edges[c])
        if (i!=p)
        {
            dfs1(i,c);
            subTree[c]+=subTree[i];
        }
}

bool isAncestor(int u, int v)
{
    if (tin[u]<=tin[v]&&tout[v]<=tout[u])
        return 1;
    return 0;
}

int lca(int u, int v)
{
    if (isAncestor(u,v))
        return u;
    if (isAncestor(v,u))
        return v;
    for (int i=lg-1;i+1;--i)
        if (!isAncestor(up[i][u],v))
            u=up[i][u];
    return up[0][u];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,w;
    cin>>n>>m;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    tin[0]=0;
    tout[0]=1e9;
    while (m--)
    {
        cin>>u>>v;
        ++subTree[u];
        ++subTree[v];
        w=lca(u,v);
        --subTree[w];
        --subTree[up[0][w]];
    }
    dfs1(1,0);
    for (int i=1;i<=n;++i)
        cout<<subTree[i]<<" ";
    return 0;
}