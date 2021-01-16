#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7, mn = 1e6+1;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll fact[mn];

ll mult(ll a, ll b)
{
    return (a*b)%mod;
}

ll divide(ll a, ll b)
{
    return (a*binpow(b,mod-2))%mod;
}

ll C(ll a, ll b)
{
    return divide(fact[a],(mult(fact[b],fact[a-b])%mod));
}

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    fact[0]=1;
    for (int i=1;i<mn;++i)
        fact[i]=(fact[i-1]*i)%mod;
    ll ans=0;
    for (int i=1;i+1<n&&i<=m;++i)
        ans=add(ans,mult(mult(divide(fact[n-2],fact[n-i-1]),C(m-1,i-1)),mult(binpow(m,n-1-i),mult(i+1,binpow(n,n-i-2)))));
    if (n-1<=m)
        ans=add(ans,mult(fact[n-2],C(m-1,n-2)));
    cout<<ans;
    return 0;
}