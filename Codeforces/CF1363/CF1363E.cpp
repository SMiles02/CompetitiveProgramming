#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
using pll = pair<ll,ll>;

ll min(ll x, ll y)
{
    if (x>y)
        return y;
    return x;
}

int a[200001];
int b[200001];
int c[200001];
vector<int> edges[200001];

pair<pll,pll> dfs(int cur, int pt)
{
    a[cur]=min(a[cur],a[pt]);
    ll x=0,y=0,z=0,w=0;
    pair<pll,pll> p;
    if (b[cur]==0&&c[cur]==1)
        ++x;
    else if (b[cur]==1&&c[cur]==0)
        ++y;
    else
        ++z;
    for (int i : edges[cur])
        if (i!=pt)
        {
            p=dfs(i,cur);
            x+=p.first.first;
            y+=p.first.second;
            z+=p.second.first;
            w+=p.second.second;
        }
    if (x!=y)
    {
        if (x>y)
            return {{x-y,0},{z,w+a[cur]*(y*2)}};
        return {{0,y-x},{z,w+a[cur]*(x*2)}};

    }
    return {{0,0},{z,w+a[cur]*(x+y)}};
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0]=1e9;
    int n,u,v;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i]>>c[i];
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    pair<pll,pll> p = dfs(1,1);
    if (p.first.first!=p.first.second)
        cout<<-1;
    else
        cout<<p.second.second;
    return 0;
}