#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll binpow(ll a, ll b) {
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res*a)%mod;
    return res;
}

ll pos(ll x)
{
    if (x<0)
        x+=mod;
    return x;
}

ll ad(ll x, ll y)
{
    if (x+y>=mod)
        return x+y-mod;
    return x+y;
}

set<pair<ll,ll>> m[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    string s;
    cin>>s;
    n=sz(s);
    ll p1[n+1];
    ll p2[n+1];
    ll dp[n+1];
    ll im1[n+1];
    ll im2[n+1];
    ll h1[n+1];
    ll h2[n+1];
    h1[0]=0;
    h2[0]=0;
    ll s1,s2,x,y;
    dp[0]=1;
    p1[0]=1;p2[0]=1;
    im1[0]=1;im2[0]=1;
    p1[1]=uniform_int_distribution<int>(1000,10000)(rng);
    p2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    while (p1[1]==p2[1])
        p2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    im1[1]=binpow(p1[1],mod-2);
    im2[1]=binpow(p2[1],mod-2);
    h1[1]=p1[0]*(s[0]-'a'+1);
    h1[1]%=mod;
    h2[1]=p2[0]*(s[0]-'a'+1);
    h2[1]%=mod;
    for (int i=1;i<n;++i)
    {
        p1[i+1]=p1[i]*p1[1];
        p1[i+1]%=mod;
        p2[i+1]=p2[i]*p2[1];
        p2[i+1]%=mod;
        im1[i+1]=im1[i]*im1[1];
        im1[i+1]%=mod;
        im2[i+1]=im2[i]*im2[1];
        im2[i+1]%=mod;
        h1[i+1]=h1[i]+p1[i]*(s[i]-'a'+1);
        h1[i+1]%=mod;
        h2[i+1]=h2[i]+p2[i]*(s[i]-'a'+1);
        h2[i+1]%=mod;
    }
    cin>>k;
    while (k--)
    {
        cin>>s;
        x=sz(s);
        if (x>n)
            continue;
        s1=0;s2=0;
        for (int i=0;i<x;++i)
        {
            s1+=p1[i]*(s[i]-'a'+1);
            s1%=mod;
            s2+=p2[i]*(s[i]-'a'+1);
            s2%=mod;
        }
        m[x].insert({s1,s2});
    }
    for (int i=1;i<=n;++i)
    {
        dp[i]=0;
        for (int j=0;j<i;++j)
        {
            x=(pos(h1[i]-h1[j])*im1[j])%mod;
            y=(pos(h2[i]-h2[j])*im2[j])%mod;
            if (m[i-j].find({x,y})!=m[i-j].end())
                dp[i]=ad(dp[i],dp[j]);
        }
    }
    cout<<dp[n];
    return 0;
}