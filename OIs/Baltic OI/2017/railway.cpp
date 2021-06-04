#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+4, lg = 17;
int tin[N], tout[N], t, up[lg][N], p[N][2], a[N], s[N], k;
vector<int> ans;
vector<array<int,2>> e[N];

void dfs(int c)
{
    tin[c]=++t;
    up[0][c]=p[c][0];
    for (int i=1;i<lg;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    for (auto i : e[c])
        if (i[0]!=p[c][0])
        {
            p[i[0]][0]=c;
            p[i[0]][1]=i[1];
            dfs(i[0]);
        }
    tout[c]=++t;
}

bool cmp(int x, int y)
{
    return tin[x] < tin[y];
}

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

void dfsAns(int c)
{
    for (auto i : e[c])
        if (i[0]!=p[c][0])
        {
            dfsAns(i[0]);
            a[c]+=a[i[0]];
        }
    if (a[c]>=k*2)
        ans.push_back(p[c][1]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m>>k;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    dfs(1);
    tout[0]=++t;
    while (m--)
    {
        cin>>x;
        for (int i=0;i<x;++i)
            cin>>s[i];
        sort(s,s+x,cmp);
        s[x]=s[0];
        for (int i=0;i<x;++i)
        {
            ++a[s[i]];
            ++a[s[i+1]];
            a[lca(s[i],s[i+1])]-=2;
        }
    }
    dfsAns(1);
    cout<<ans.size()<<"\n";
    sort(ans.begin(), ans.end());
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}