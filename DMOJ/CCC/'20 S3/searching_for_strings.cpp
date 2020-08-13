#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
string s,t; //needle, haystack
int mod=1e9+7;

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;
    return res;
}

void hashIt(int l, int r, int n, ll a[], ll I[], ll p[])
{
    a[0]=0;
    p[0]=1;
    p[1]=uniform_int_distribution<int>(l,r)(rng);
    I[0]=binpow(p[1],mod-2);
    for (int i=1;i<=n;++i)
    {
        p[i]=(p[i-1]*p[1])%mod;
        I[i]=(I[i-1]*I[0])%mod;
    }
    for (int i=0;i<n;++i)
        a[i+1]=(a[i]+p[i]*(t[i]-'a'+1))%mod;
}

int c[26];
int d[26];

bool same()
{
    for (int i=0;i<26;++i)
        if (c[i]!=d[i])
            return 0;
    return 1;
}

ll sub(ll a, ll b)
{
    a-=b;
    if (a<0)
        a+=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>s;
    cin>>t;
    int n=sz(t), m=sz(s);
    ll h1[n+1];
    ll h2[n+1];
    ll p1[n+1];
    ll p2[n+1];
    ll i1[n+1];
    ll i2[n+1];
    hashIt(1000,5000,n,h1,i1,p1);
    hashIt(5001,10000,n,h2,i2,p2);
    set<pair<ll,ll>> se;
    for (auto i : s)
        ++c[(i-'a')];
    for (int i=0;i<m;++i)
        ++d[(t[i]-'a')];
    if (same())
        se.insert({h1[m],h2[m]});
    for (int i=m;i<n;++i)
    {
        ++d[(t[i]-'a')];
        --d[(t[i-m]-'a')];
        if (same())
            se.insert({(sub(h1[i+1],h1[i+1-m])*i1[i-m])%mod,(sub(h2[i+1],h2[i+1-m])*i2[i-m])%mod});
    }
    cout<<sz(se);
    return 0;
}