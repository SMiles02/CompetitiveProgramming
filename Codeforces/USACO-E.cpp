#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll val[1001];
int p[1001];
vector<int> edges[1001];

ll ans(ll cur)
{
    if (cur==1)
        return val[1];
    else
        return val[cur]-ans(p[cur]);
}

void dfs(int c, int l)
{
    p[c]=l;
    for (int x : edges[c])
        if (x!=l)
            dfs(x,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v;
    cin>>n>>m;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    for (int i=0;i<m;++i)
    {
        cin>>u;
        if (u==1)
        {
            cin>>u>>v;
            val[u]+=v;
        }
        else
        {
            cin>>v;
            cout<<a[v]+ans(v)<<"\n";
        }
    }
    return 0;
}