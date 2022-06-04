#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+1, lg = 17;
int h[N],tin[N],tout[N],up[lg][N],t;
vector<int> e[N], path[lg][N], d[N];

void print(vector<int> v, int k)
{
    k=min(k,sz(v));
    cout<<k;
    for (int i=0;i<k;++i)
        cout<<" "<<v[i];
    cout<<"\n";
}

vector<int> merge(vector<int> v, vector<int> w)
{
    int x=v.size(),y=w.size(),a=0,b=0;
    vector<int> r;
    for (int i=0;i<10;++i)
    {
        if (a<x&&b<y)
        {
            if (v[a]==w[b])
            {
                r.push_back(v[a++]);
                ++b;
            }
            else if (v[a]<w[b])
                r.push_back(v[a++]);
            else
                r.push_back(w[b++]);
        }
        else if (a<x)
            r.push_back(v[a++]);
        else if (b<y)
            r.push_back(w[b++]);
        else
            return r;
    }
    return r;
}

void dfs(int c, int p, int H)
{
    tin[c]=++t;
    h[c]=H;
    sort(d[c].begin(), d[c].end());
    while (sz(d[c])>10)
        d[c].pop_back();
    up[0][c]=p;
    path[0][c]=merge(d[c],d[p]);
    for (int i=1;i<lg;++i)
    {
        up[i][c]=up[i-1][up[i-1][c]];
        path[i][c]=merge(path[i-1][c],path[i-1][up[i-1][c]]);
    }
    for (int i : e[c])
        if (i!=p)
            dfs(i,c,H+1);
    tout[c]=++t;
}

bool isAncestor(int a, int b)
{
    if (tin[a]<=tin[b]&&tout[b]<=tout[a])
        return 1;
    return 0;
}

int lca(int a, int b)
{
    if (isAncestor(a,b))
        return a;
    if (isAncestor(b,a))
        return b;
    for (int i=lg-1;i>=0;--i)
        if (!isAncestor(up[i][a],b))
            a=up[i][a];
    return up[0][a];
}

vector<int> getPath(int x, int y)
{
    vector<int> v;
    for (int i=0;i<min(10,sz(d[x]));++i)
        v.push_back(d[x][i]);
    for (int i=0;i<lg;++i)
        if ((1<<i)&y)
        {
            v=merge(v,path[i][x]);
            x=up[i][x];
        }
    return v;
}

int dist(int a, int b)
{
    return h[a]-h[b];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,x,y,a;
    cin>>n>>m>>q;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        d[x].push_back(i);
    }
    dfs(1,0,0);
    tout[0]=++t;
    while (q--)
    {
        cin>>x>>y>>a;
        m=lca(x,y);
        print(merge(getPath(x,dist(x,m)),getPath(y,dist(y,m))),a);
    }
    return 0;
}