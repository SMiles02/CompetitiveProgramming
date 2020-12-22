#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 998244353;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = a * a;
        a%=mod;
        b >>= 1;
    }
    return res;
}

ll inv(ll a, ll b)
{
    return (a*binpow(b,mod-2))%mod;
}

ll f[500000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<500000;++i)
        f[i]=(f[i-1]*i)%mod;
    int n;
    cin>>n;
    ll ans=0;
    int a[2*n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>a[i+n];
    sort(a,a+2*n);
    for (int i=0;i<n;++i)
        ans-=a[i];
    for (int i=0;i<n;++i)
        ans+=a[i+n];
    cout<<inv(((ans%mod)*f[2*n])%mod,binpow(f[n],2));
    return 0;
}