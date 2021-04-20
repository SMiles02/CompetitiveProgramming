#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1, lg = 19;
int m,ans,h[N],up[N][lg],pt[N],sub[N],tin[N],tout[N],t;
vector<int> edges[N];
map<int,int> H[N];
set<int> black[N];

void lcaDfs(int c, int p, int x)
{
    h[c]=x;
    up[c][0]=p;
    for (int i=1;i<lg;++i)
        up[c][i]=up[up[c][i-1]][i-1];
    tin[c]=++t;
    for (int i : edges[c])
        if (i!=p)
            lcaDfs(i,c,x+1);
    tout[c]=++t;
}

bool isAncestor(int x, int y)
{
    if (tin[x]<=tin[y]&&tin[y]<=tout[x])
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

void solve(int c, int p);

void dfs(int c, int p)
{
    sub[c]=1;
    for (int i : edges[c])
        if (i!=p&&!black[c].count(i))
        {
            dfs(i,c);
            sub[c]+=sub[i];
        }
}

bool dfs(int c, int p, int r, int centP)
{
    int mx = sub[r] - sub[c];
    for (int i : edges[c])
        if (i!=p&&!black[c].count(i))
        {
            if (dfs(i,c,r,centP))
                return 1;
            mx=max(mx,sub[i]);
        }
    if (mx<=sub[r]/2)
    {
        pt[c]=centP;
        int x;
        for (int i=c;i>0;i=pt[i])
        {
            x=dist(c,i);
            ans+=H[i][m-x];
            ++H[i][x];
        }
        cout<<c<<" "<<ans<<"\n";
        for (int i : edges[c])
            if (!black[c].count(i))
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
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
    cout<<ans;
    return 0;
}