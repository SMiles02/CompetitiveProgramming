#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN = 2e5+1, lg = 19; //maximum number of nodes;
int h[MAXN], timer, up[MAXN][lg], tin[MAXN], tout[MAXN]; //change 19 to log2(MAXN)+2
vector<int> edges[MAXN];

void dfs(int c, int p, int x)
{
    tin[c]=++timer;
    h[c]=x;
    up[c][0] = p;
    for (int i=1;i<lg;++i)
        up[c][i] = up[up[c][i-1]][i-1];
    for (int i : edges[c])
        if (i != p)
            dfs(i,c,x+1);
    tout[c]=++timer;
}

bool isAncestor(int p, int c) //checking if p is an ancestor of c
{
    if (tin[p]<=tin[c]&&tout[c]<=tout[p])
        return 1;
    return 0;
}

int lca(int u, int v)
{
    if (isAncestor(u,v))
        return u;
    if (isAncestor(v,u))
        return v;
    for (int i=18;i>=0;--i)
        if (!isAncestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}

int dist(int x, int y)
{
    return h[x]+h[y]-2*h[lca(x,y)];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0,0);
    tout[0]=++timer;
    while (q--)
    {
        cin>>x>>y;
        if (dist(x,y)&1)
            cout<<"Road\n";
        else
            cout<<"Town\n";
    }
    return 0;
}