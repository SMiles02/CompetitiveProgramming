#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5+4, lg = 20;
const ll INF = 1e18;
int pt[N], sub[N], up[lg][N], tin[N], tout[N], ct;
ll h[N], ans[N];
pair<int,ll> lift[N][lg];
vector<array<int,2>> e[N];
bitset<N> b;

bool isAncestor(int x, int y)
{
    return (tin[x]<=tin[y]&&tout[y]<=tout[x]);
}

int lca(int x, int y)
{
    if (isAncestor(x,y))
        return x;
    if (isAncestor(y,x))
        return y;
    for (int i=lg-1;i>=0;--i)
        if (!isAncestor(up[i][x],y))
            x=up[i][x];
    return up[0][x];
}

ll dist(int x, int y)
{
    int z = lca(x,y);
    return h[x]+h[y]-h[z]*2;
}

void lcaDfs(int c, int p, ll x)
{
    tin[c]=++ct;
    h[c]=x;
    up[0][c]=p;
    for (int i=1;i<lg;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (auto i : e[c])
        if (i[0]!=p)
            lcaDfs(i[0],c,x+i[1]);
    tout[c]=++ct;
}

void subDfs(int c, int p)
{
    sub[c]=1;
    for (auto i : e[c])
        if (i[0]!=p&&!b[i[0]])
        {
            subDfs(i[0],c);
            sub[c]+=sub[i[0]];
        }
}

void centDfs(int c, int p, int t)
{
    int mx=t-sub[c];
    for (auto i : e[c])
        if (i[0]!=p&&!b[i[0]])
        {
            centDfs(i[0],c,t);
            mx=max(mx,sub[i[0]]);
        }
    if (mx<=t/2)
        ct=c;
}

void solve(int r, int p)
{
    subDfs(r,0);
    centDfs(r,0,sub[r]);
    int X = ct;
    pt[X]=p;
    b[X]=1;
    for (auto i : e[X])
        if (!b[i[0]])
            solve(i[0],X);
}

void Init(int n, int A[], int B[], int w[])
{
    for (int i=0;i<n-1;++i)
    {
        ans[i+1]=INF;
        e[++A[i]].push_back({++B[i],w[i]});
        e[B[i]].push_back({A[i],w[i]});
    }
    ans[n]=INF;
    lcaDfs(1,0,0);
    tout[0]=++ct;
    solve(1,0);
    for (int i=1;i<=n;++i)
        for (int j=0,k=i;k!=0;++j,k=pt[k])
        {
            lift[i][j].first=k;
            lift[i][j].second=dist(i,k);
        }
}

ll Query(int s, int x[], int t, int y[])
{
    for (int i=0;i<s;++i)
    {
        ++x[i];
        for (int j=0;lift[x[i]][j].first!=0;++j)
            ans[lift[x[i]][j].first]=min(ans[lift[x[i]][j].first],lift[x[i]][j].second);
    }
    ll ret = INF;
    for (int i=0;i<t;++i)
    {
        ++y[i];
        for (int j=0;lift[y[i]][j].first!=0;++j)
            ret=min(ret,ans[lift[y[i]][j].first]+lift[y[i]][j].second);
    }
    for (int i=0;i<s;++i)
        for (int j=0;lift[x[i]][j].first!=0;++j)
            ans[lift[x[i]][j].first]=INF;
    return ret;
}