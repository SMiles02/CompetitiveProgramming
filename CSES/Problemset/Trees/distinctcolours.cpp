#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn=2e5+5;
int a[mn],b[mn],in[mn],bit[mn],t;
vector<array<int,2>> q[mn];
vector<int> edges[mn];

void update(int i, int d)
{
    while (i<mn)
    {
        bit[i]+=d;
        i+=(i&-i);
    }
}

int pre(int i)
{
    int x=0;
    while (i)
    {
        x+=bit[i];
        i-=(i&-i);
    }
    return x;
}

int query(int l, int r)
{
    return pre(r) - pre(l-1);
}

void dfs(int c, int p)
{
    in[c]=++t;
    b[t]=a[c];
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c);
    q[t].push_back({in[c],c});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    map<int,int> m;
    for (int i=1;i<=n;++i)
    {
        if (m[b[i]])
            update(m[b[i]],-1);
        update(i,1);
        m[b[i]]=i;
        for (auto j : q[i])
            a[j[1]]=query(j[0],i);
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}