#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+1;
int col[mn], t, x, y;
vector<int> edges[mn], edges2[mn];

void dfs(int c, int p, int g)
{
    int m=g;
    if (col[c]^col[p])
    {
        m=++t;
        if (c^1)
        {
            edges2[g].push_back(m);
            edges2[m].push_back(g);
        }
    }
    for (int i : edges[c])
        if (i^p)
            dfs(i,c,m);
}

void dfs2(int c, int p, int h)
{
    if (h>=x)
    {
        x=h;
        y=c;
    }
    for (int i : edges2[c])
        if (i^p)
            dfs2(i,c,h+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    cin>>n;
    col[0]=69;
    for (int i=1;i<=n;++i)
        cin>>col[i];
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,0);
    dfs2(1,0,0);
    dfs2(y,0,0);
    cout<<(x+1)/2;
    return 0;
}