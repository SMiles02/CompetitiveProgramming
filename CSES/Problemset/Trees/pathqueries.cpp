#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1, MN = 4e5+1;
vector<int> edges[mn];
int id[mn],ed[mn],val[mn],t;
ll bit[MN];

void update(int i, int x)
{
    for (;i<MN;i+=(i&-i))
        bit[i]+=x;
}

ll query(int i)
{
    ll r=0;
    for (;i;i-=(i&-i))
        r+=bit[i];
    return r;
}

void dfs(int c, int p)
{
    id[c]=++t;
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
    ed[c]=++t;
    update(id[c],val[c]);
    update(ed[c],-val[c]);
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
            update(ed[x],val[x]-y);
            val[x]=y;
        }
        else
        {
            cin>>x;
            cout<<query(id[x])<<"\n";
        }
    }
    return 0;
}