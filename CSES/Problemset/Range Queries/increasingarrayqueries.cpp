#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 2e5+7;
int n,a[mn],nt[mn];
ll bit[2][mn],ans[mn];
vector<array<int,2>> lPair[mn];

void update(int j, int i, ll d)
{
    while (i<=n)
    {
        bit[j][i]+=d;
        i+=i&-i;
    }
}

ll query(int j, int i)
{
    ll rtn = 0;
    while (i)
    {
        rtn+=bit[j][i];
        i-=i&-i;
    }
    return rtn;
}

ll query(int j, int l, int r)
{
    return query(j, r) - query(j, l-1);
}

void handleQueries(int l)
{
    for (auto i : lPair[l])
    {
        int x=query(1,i[0]),y=0,z=0;
        for (int j=17;j>=0;--j)
            if (z+(1<<j)<=i[0])
                if (y+bit[1][z+(1<<j)]<x)
                {
                    z+=(1<<j);
                    y+=bit[1][z];
                }
        ++z;
        if (z==i[0])
            ans[i[1]]=query(0,l,i[0])-query(0,i[0],i[0]);
        else
            ans[i[1]]=query(0,l,i[0])-(1LL*a[z]*(nt[z]-i[0]-1));
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q,x,y;
    cin>>n>>q;
    ll v[n+2];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    a[n+1]=1e9+7;
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        lPair[x].push_back({y,i});
    }
    stack<int> s;
    s.push(n+1);
    for (int i=n;i;--i)
    {
        while (a[s.top()]<=a[i])
            s.pop();
        nt[i]=s.top();
        s.push(i);
    }
    x=1;
    for (int i=1;i<=n;++i)
    {
        if (x==i)
        {
            v[i]=1LL*a[i]*(nt[i]-i-1);
            x=nt[i];
            update(1,i,1);
        }
        else
            v[i]=-a[i];
        update(0,i,v[i]);
    }
    v[n+1]=1;
    handleQueries(1);
    for (int i=2;i<=n;++i)
    {
        x=i;
        while (v[x]<0)
        {
            update(0,x,1LL*a[x]*(nt[x]-x-1)-v[x]);
            update(1,x,1);
            v[x]=1LL*a[x]*(nt[x]-x-1);
            x=nt[x];
        }
        handleQueries(i);
    }
    for (int i=0;i<q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}