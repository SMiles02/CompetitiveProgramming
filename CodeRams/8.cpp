#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 1e5+5;
ll bit[mn];

ll pre(int i)
{
    ll x=0;
    while (i)
    {
        x+=bit[i];
        i-=(i&(-i));
    }
    return x;
}

ll query(ll l, ll r)
{
    return pre(r)-pre(l-1);
}

void update(int i, int d)
{
    while (i<mn)
    {
        bit[i]+=d;
        i+=(i&-i);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x;
    ll ans=0;
    cin>>n;
    vector<pii> v;
    v.push_back({-1e9,69});
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        x=0;
        while ((k&1)^1)
        {
            ++x;
            k>>=1;
        }
        if (x)
            v.push_back({-x,i});
    }
    sort(v.begin(), v.end());
    for (int i=1;i<sz(v);++i)
    {
        //cout<<v[i].f<<" "<<v[i].s<<"\n";
        //cout<<v[i].s<<" "<<i<<" "<<query(v[i].s+1,n+1)<<"\n";
        ans+=query(v[i].s+1,n+1)+v[i].s-i;
        //cout<<v[i].s-i-2*pre(v[i].s)+pre(i)+pre(n)<<"\n";
        update(v[i].s,1);
    }
    cout<<ans;
    return 0;
}