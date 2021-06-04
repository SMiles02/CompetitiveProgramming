//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+4;
int n;
ll a[N],s;
vector<array<ll,2>> e[N];

void dfs(int c, ll x)
{
    a[c]=x;
    for (auto i : e[c])
        dfs(i[0],x^i[1]);
}

void find(ll x, ll y)
{
    if (y<a[1]||a[n]<x)
        return;
    int i,j,l,r,m;
    l=1;r=n;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (a[m]<x)
            l=m+1;
        else
            r=m;
    }
    i=l;
    l=1;r=n;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (y<a[m])
            r=m-1;
        else
            l=m;
    }
    j=l;
    s+=max(0,j-i+1);
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll l=0,r=(1LL<<62)-1,m,k,x,y;
    cin>>n>>k;
    for (int i=2;i<=n;++i)
    {
        cin>>x>>y;
        e[x].push_back({i,y});
    }
    dfs(1,0);
    sort(a+1,a+n+1);
    while (l<r)
    {
        m=l+(r-l)/2;
        s=0;
        for (int i=1;i<=n;++i)
        {
            x=0;
            for (int j=61;j>=0;--j)
            {
                if ((m&(1LL<<j))==0)
                {
                    if (a[i]&(1LL<<j))
                        x+=(1LL<<j);
                }
                else
                {
                    if ((a[i]&(1LL<<j))==0)
                    {
                        find(x,x+(1LL<<j)-1);
                        x+=(1LL<<j);
                    }
                    else
                        find(x+(1LL<<j),x+(1LL<<(j+1))-1);
                }
            }
            find(x,x);
        }
        if (s>=k)
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}