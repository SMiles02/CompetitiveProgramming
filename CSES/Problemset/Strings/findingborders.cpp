#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;

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

ll pos(ll a)
{
    if (a<0)
        a+=mod;
    return a;
}

ll p1[1000001];
ll p2[1000001];
ll im1[1000001];
ll im2[1000001];
ll h1[1000001];
ll h2[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    string s;
    cin>>s;
    n=sz(s);
    p1[0]=1;p2[0]=1;
    p1[1]=uniform_int_distribution<int>(1000,10000)(rng);
    p2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    while (p2[1]==p1[1])
        p2[1]=uniform_int_distribution<int>(1000,10000)(rng);
    im1[0]=1;im2[0]=1;
    im1[1]=binpow(p1[1],mod-2);
    im2[1]=binpow(p2[1],mod-2);
    for (int i=2;i<1000001;++i)
    {
        p1[i]=p1[i-1]*p1[1];
        p1[i]%=mod;
        p2[i]=p2[i-1]*p2[1];
        p2[i]%=mod;
        im1[i]=im1[i-1]*im1[1];
        im1[i]%=mod;
        im2[i]=im2[i-1]*im2[1];
        im2[i]%=mod;
    }
    for (int i=0;i<n;++i)
    {
        h1[i+1]=h1[i]+(p1[i]*((s[i]-'a')+1));
        h1[i+1]%=mod;
        h2[i+1]=h2[i]+(p2[i]*((s[i]-'a')+1));
        h2[i+1]%=mod;
    }
    for (int i=1;i<n;++i)
        if (h1[i]==(pos(h1[n]-h1[n-i])*im1[n-i])%mod)
            if (h2[i]==(pos(h2[n]-h2[n-i])*im2[n-i])%mod)
                cout<<i<<" ";
    return 0;
}