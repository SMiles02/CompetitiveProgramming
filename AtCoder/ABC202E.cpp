#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int h[N], ans[N], cnt[N], a[N], tin[N], tout[N], t, sz[N];
vector<int> e[N];
vector<array<int,2>> v[N];

void build(int c, int x)
{
    tin[c]=++t;
    a[t]=c;
    h[c]=x;
    sz[c]=1;
    for (int i : e[c])
    {
        build(i,x+1);
        sz[c]+=sz[i];
    }
    tout[c]=t;
}

void dfs(int c, bool keep)
{
    int mx=-1,bC=-1;
    for (int i : e[c])
        if (sz[i]>mx)
        {
            mx=sz[i];
            bC=i;
        }
    for (int i : e[c])
        if (i!=bC)
            dfs(i,0);
    if (bC!=-1)
        dfs(bC,1);
    for (int i : e[c])
        if (i!=bC)
            for (int j=tin[i];j<=tout[i];++j)
                ++cnt[h[a[j]]];
    ++cnt[h[c]];
    for (auto i : v[c])
        ans[i[0]]=cnt[i[1]];
    if (keep==0)
        for (int j=tin[c];j<=tout[c];++j)
            --cnt[h[a[j]]];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n;
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        e[x].push_back(i);
    }
    cin>>q;
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        v[x].push_back({i,y});
    }
    build(1,0);
    dfs(1,1);
    for (int i=0;i<q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}