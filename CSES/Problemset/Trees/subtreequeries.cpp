#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+1;
ll bit[mn];
int id[mn],ed[mn],val[mn],t;
vector<int> edges[mn];

void update(int i, int x)
{
    for (;i<mn;i+=(i&-i))
        bit[i]+=x;
}

ll pre(int i)
{
    ll r=0;
    for (;i;i-=(i&-i))
        r+=bit[i];
    return r;
}

ll query(ll l, ll r)
{
    return pre(r)-pre(l-1);
}

int dfs(int c, int p)
{
    id[c]=++t;
    ed[c]=t;
    update(t,val[c]);
    for (int i : edges[c])
        if (i!=p)
            ed[c]=dfs(i,c);
    return ed[c];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>val[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    while (q--)
    {
        cin>>x;
        if (x==1)
        {
            cin>>x>>y;
            update(id[x],y-val[x]);
            val[x]=y;
        }
        else
        {
            cin>>y;
            cout<<query(id[y],ed[y])<<"\n";
        }
    }
    return 0;
}