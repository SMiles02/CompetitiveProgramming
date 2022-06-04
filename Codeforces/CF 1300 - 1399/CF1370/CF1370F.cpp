#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

int x,y,mD,ans[1001],rt;
vector<int> edges[1001], toQuery, result, dist[1001];
bitset<1001> enRoute;
bool fd=0;

void query()
{
    cout<<"? "<<toQuery.size();
    for (int i : toQuery)
        cout<<" "<<i;
    cout<<endl;
    cin>>x>>y;
    toQuery.clear();
}

void dfs(int c, int p, int h)
{
    mD=max(mD,h);
    dist[h].push_back(c);
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h+1);
}

void dfs2(int c, int p)
{
    if (c==rt)
        return;
    if (enRoute[c])
        fd=1;
    for (int i : edges[c])
        if (i!=p)
            dfs2(i,c);
}

void solve()
{
    int n,d,u,v,l,r,m,qC=0;
    string s;
    cin>>n;
    dist[0].clear();
    ans[0]=0;
    for (int i=1;i<=n;++i)
    {
        edges[i].clear();
        toQuery.push_back(i);
        dist[i].clear();
        ans[i]=0;
    }
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    query();
    vector<int> queried;
    rt=x;d=y;
    mD=0;
    dfs(rt,0,0);
    l=(d+1)/2;r=min(mD,d);
    while (l<r)
    {
        m=l+(r-l)/2+1;
        toQuery=dist[m];
        ++qC;
        query();
        ans[m]=x;
        queried.push_back(x);
        if (y>d)
            r=m-1;
        else
            l=m;
    }
    if (sz(dist[l])==1)
        u=dist[l][0];
    else if (ans[l])
        u=ans[l];
    else if (qC<9)
    {
        toQuery=dist[l];
        query();
        u=x;
    }
    else
    {
        for (int i=1;i<=n;++i)
            enRoute[i]=0;
        for (int i : queried)
            enRoute[i]=1;
        fd=0;
        for (int i : dist[l])
        {
            dfs2(i,0);
            if (fd)
            {
                u=i;
                break;
            }
        }
    }
    for (int i=0;i<=n;++i)
        dist[i].clear();
    dfs(u,0,0);
    toQuery=dist[d];
    query();
    cout<<"! "<<u<<" "<<x<<endl;
    cin>>s;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}