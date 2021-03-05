#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+4, INF = 1e9+7;
int n,a[N],seg[N<<2],bit[N],ans[N],nxt[N];
vector<int> s[N];
vector<array<int,2>> queries[N];

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>a[l];
        seg[i]=a[l];
        s[a[l]].push_back(l);
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    seg[i]=min(seg[i*2+1],seg[i*2+2]);
}

int query(int i, int cL, int cR, int l, int r)
{
    if (l<=cL&&cR<=r)
        return seg[i];
    if (cR<l||r<cL)
        return INF;
    return min(query(i*2+1,cL,cL+(cR-cL)/2,l,r),query(i*2+2,cL+(cR-cL)/2+1,cR,l,r));
}

int query(int l, int r)
{
    return query(0,1,n,l,r);
}

void update(int i, int d)
{
    while (i<=n)
    {
        bit[i]+=d;
        i+=i&-i;
    }
}

int bitQ(int i)
{
    int rtn = 0;
    while (i)
    {
        rtn+=bit[i];
        i-=i&-i;
    }
    return rtn;
}

int lb(vector<int> &v, int x)
{
    int n = v.size();
    if (v[n-1]<x)
        return n;
    int l=0,r=n-1,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (v[m]<x)
            l=m+1;
        else
            r=m;
    }
    return l;
}

void f(int l, int r)
{
    if (l>r)
        return;
    int mn = query(l,r),x,y;
    x = lb(s[mn],l);
    y = lb(s[mn],r+1);
    update(s[mn][x],1);
    for (int i=x+1;i<y;++i)
    {
        f(s[mn][i-1]+1,s[mn][i]-1);
        nxt[s[mn][i-1]]=s[mn][i];
    }
    f(l,s[mn][x]-1);
    f(s[mn][y-1]+1,r);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,x,y;
    cin>>n>>q;
    build(0,1,n);
    f(1,n);
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        queries[x].push_back({y,i});
    }
    for (int i=1;i<=n;++i)
    {
        for (auto j : queries[i])
            ans[j[1]]=bitQ(j[0]);
        update(i,-1);
        if (nxt[i])
            update(nxt[i],1);
    }
    for (int i=0;i<q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}