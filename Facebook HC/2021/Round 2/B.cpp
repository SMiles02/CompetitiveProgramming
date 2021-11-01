#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 8e5+1, L = 21; //maximum number of nodes;
int timer, up[N][L], tin[N], tout[N], a[N], ans; //change 19 to log2(N)+2
vector<int> edges[N];

void dfs(int c, int p)
{
    tin[c]=++timer;
    up[c][0] = p;
    for (int i=1;i<L;++i)
        up[c][i] = up[up[c][i-1]][i-1];
    for (int i : edges[c])
        if (i != p)
            dfs(i,c);
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
    for (int i=L-1;i>=0;--i)
        if (!isAncestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}

int dfsAns(int c, int p)
{
    for (int i : edges[c])
        if (i!=p)
            a[c]+=dfsAns(i,c);
    if (a[c]==0&&c!=1)
        ++ans;
    return a[c];
}

int solve()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        a[i]=0;
        edges[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    timer=0;
    dfs(1,0);
    tout[0]=++timer;
    vector<int> v(n+1,0);
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (v[x])
        {
            ++a[i];
            ++a[v[x]];
            a[lca(i,v[x])]-=2;
        }
        v[x]=i;
    }
    ans=0;
    dfsAns(1,0);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
        cout<<"Case #"<<i<<": "<<solve()<<"\n";
    return 0;
}