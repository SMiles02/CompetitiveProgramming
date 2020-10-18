#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 2e5 + 7, lg = 21;
int tin[maxn],tout[maxn],low[maxn],t,n,heights[4*maxn], up[lg][4*maxn];
vector<int> edges[maxn],bctEdges[4*maxn];
bitset<maxn> done;
set<pair<int,int>> s;

void dfs(int c, int p)
{
    done[c]=1;
    tin[c] = low[c] = ++t;
    for (int i : edges[c])
        if (i!=p)
        {
            if (done[i])
            {
                low[c]=min(low[c],tin[i]);
                continue;
            }
            dfs(i,c);
            low[c]=min(low[c],low[i]);
            if (tin[c]<=low[i])
            {
                s.insert({c,i});
                s.insert({i,c});
            }
        }
}

void dfs2(int c, int k)
{
    bctEdges[k].push_back(c);
    bctEdges[c].push_back(k);
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
        {
            if (s.find({c,i})!=s.end())
            {
                bctEdges[t+1].push_back(c);
                bctEdges[c].push_back(t+1);
                dfs2(i,++t);
            }
            else
                dfs2(i,k);
        }
}

void bctDfs(int c, int p, int h)
{
    tin[c]=++t;
    heights[c]=h;
    up[0][c]=p;
    for (int i=1;i<lg;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (int i : bctEdges[c])
        if (i!=p)
            bctDfs(i,c,h+1);
    tout[c]=++t;
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

int dist(int u, int v)
{
    return heights[u] + heights[v] - (2*heights[lca(u,v)]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,q,u,v,a,b,c;
    cin>>n>>m>>q;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    t=n+1;
    done.reset();
    dfs2(1,n+1);
    t=0;
    bctDfs(1,0,0);
    tout[0]=++t;
    while (q--)
    {
        cin>>a>>b>>c;
        if (dist(a,b)==dist(a,c)+dist(b,c))
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}