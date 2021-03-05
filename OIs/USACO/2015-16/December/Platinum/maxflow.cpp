#include <bits/stdc++.h>
using namespace std;

const int mn = 5e4+1, lg = 18;
int ans[mn],up[mn][lg], tin[mn], tout[mn], t;
vector<int> edges[mn];

void dfs(int c, int p)
{
    up[c][0]=p;
    for (int i=1;i<lg;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    tin[c]=++t;
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
    tout[c]=++t;
}

bool isAncestor(int x, int y)
{
    if (tin[x]<=tin[y]&&tout[y]<=tout[x])
        return 1;
    return 0;
}

int lca(int x, int y)
{
    if (isAncestor(x,y))
        return x;
    if (isAncestor(y,x))
        return y;
    for (int i=lg-1;i>=0;--i)
        if (!isAncestor(up[x][i],y))
            x=up[x][i];
    return up[x][0];
}

void dfsAns(int c, int p)
{
    for (int i : edges[c])
        if (i!=p)
        {
            dfsAns(i,c);
            ans[c]+=ans[i];
        }
    t=max(t,ans[c]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("maxflow.in", "r", stdin);
    freopen("maxflow.out", "w", stdout);
    int n,k,x,y,z;
    cin>>n>>k;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    tout[0]=++t;
    while (k--)
    {
        cin>>x>>y;
        z=lca(x,y);
        ++ans[x];
        ++ans[y];
        --ans[z];
        --ans[up[z][0]];
    }
    t=0;
    dfsAns(1,0);
    cout<<t;
	return 0;
}