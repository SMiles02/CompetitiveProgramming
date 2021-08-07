#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

struct segtree
{
    int n;
    ll MX_VAL;
    vector<ll> v;
    segtree(int n, ll k) : n(n), MX_VAL(k), v(n*4+20, k) {}
    void update(int i, int l, int r, int j, ll x)
    {
        if (j<l||r<j)
            return;
        if (l==r)
        {
            v[i]=min(v[i],x);
            return;
        }
        int m=l+(r-l)/2;
        if (j<=m)
            update(i*2+1,l,m,j,x);
        else
            update(i*2+2,m+1,r,j,x);
        v[i]=min(v[i*2+1],v[i*2+2]);
    }
    void update(int i, ll x)
    {
        update(0,0,n,i,x);
    }
    ll query(int i, int l, int r, int qL, int qR)
    {
        if (r<qL||qR<l)
            return MX_VAL;
        if (qL<=l&&r<=qR)
            return v[i];
        int m=l+(r-l)/2;
        return min(query(i*2+1,l,m,qL,qR),query(i*2+2,m+1,r,qL,qR));
    }
    ll query(int l, int r)
    {
        if (l>r)
            return MX_VAL;
        return query(0,0,n,l,r);
    }
};

void solve()
{
    int n,t=0;
    ll ans=0;
    cin>>n;
    int a[n+1];
    vector<int> r(n+2,n+1);
    set<int> s;
    segtree s1(n,n+1), s2(n,n+1), s3(n,n+1), s4(n,n+1);
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    map<int,int> mp;
    for (auto i : s)
        mp[i]=++t;
    for (int i=1;i<=n;++i)
    {
        a[i]=mp[a[i]];
        //cout<<a[i]<<" ";
    }
    //cout<<"\n";
    for (int i=n;i;--i)
    {
        r[i]=r[i+1];
        r[i]=min({r[i],s1.query(1,a[i]),s3.query(a[i],n)});
        ans+=r[i]-i;
        s1.update(a[i],s2.query(1,a[i]));
        s3.update(a[i],s4.query(a[i],n));
        s2.update(a[i],i);
        s4.update(a[i],i);
    }
    cout<<ans<<"\n";
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}