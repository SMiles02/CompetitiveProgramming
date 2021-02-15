#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 998244353;
ll f[10001];

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

ll C(int n, int k)
{
    return (f[n]*binpow((f[k]*f[n-k])%mod,mod-2))%mod;
}

ll add(ll a, ll b)
{
    return (a+b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    ll ans=0;
    cin>>n>>m;
    f[0]=1;
    for (int i=1;i<10001;++i)
        f[i]=(f[i-1]*i)%mod;
    for (int i=n*m;i>=0;i-=2)
    {
        ans=add(ans,C(n*m,i));
        //cout<<i<<" "<<C(n*m,i)<<"\n";
    }
    cout<<ans;
    return 0;
}