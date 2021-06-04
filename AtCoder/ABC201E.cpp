#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const int N = 2e5+7, mod = 1e9+7;
ll a[N];
vector<array<int,2>> e[N];

void dfs(int c, int p, int x)
{
    a[c]=x;
    for (auto i : e[c])
        if (i[0]!=p)
            dfs(i[0],c,x^i[1]);
}

int ct[60];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    ll ans=0;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    dfs(1,0,0);
    for (int i=1;i<=n;++i)
    {
        //cout<<a[i]<<" ";
        for (int j=0;j<60;++j)
            if (a[i]&(1LL<<j))
                ++ct[j];
    }
    //cout<<"\n";
    for (int i=0;i<60;++i)
    {
        //cout<<ct[i]<<"\n";
        ans=(ans+(((((1LL<<i)%mod)*(ct[i]))%mod)*(n-ct[i])))%mod;
    }
    cout<<ans;
    return 0;
}