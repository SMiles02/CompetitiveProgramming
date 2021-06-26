#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1, lg = 18, INF = 1e9;
int pt[mn],h[mn],sub[mn],tin[mn],tout[mn],up[mn][lg],d[mn],t;
vector<int> edges[mn];
set<int> black[mn];

void solve(int c, int p);

void lcaDfs(int c, int p, int x)
{
    tin[c]=++t;
    up[c][0]=p;
    h[c]=x;
    d[c]=INF;
    for (int i=1;i<lg;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    for (int i : edges[c])
        if (i!=p)
            lcaDfs(i,c,x+1);
    tout[c]=++t;
}

void dfs(int c, int p)
{
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p&&black[c].count(i)==0)
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}

bool dfs(int c, int p, int r, int centP)
{
    int mx = sub[r]-sub[c];
    for (int i : edges[c])
        if (i!=p&&black[c].count(i)==0)
        {
            if (dfs(i,c,r,centP))
                return 1;
            mx=max(mx,sub[i]);
        }
    if (mx<=sub[r]/2)
    {
        pt[c]=centP;
        for (int i : edges[c])
            if (black[c].count(i)==0)
            {
                black[i].insert(c);
                solve(i,c);
            }
        return 1;
    }
    return 0;
}

void solve(int c, int p)
{
    dfs(c,0);
    dfs(c,0,c,p);
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

int dist(int x, int y)
{
    return h[x] + h[y] - 2*h[lca(x,y)];
}

void update(int x)
{
    for (int i=x;i;i=pt[i])
        d[i]=min(d[i],dist(i,x));
}

void query(int x)
{
    int r = INF;
    for (int i=x;i;i=pt[i])
        r=min(r,dist(x,i)+d[i]);
    cout<<r<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    lcaDfs(1,0,0);
    tout[0]=++t;
    solve(1,0);
    update(1);
    while (m--)
    {
        cin>>x>>y;
        if (x==1)
            update(y);
        else
            query(y);
    }
    return 0;
}