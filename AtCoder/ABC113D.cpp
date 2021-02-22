#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 998244353;

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

ll sub(ll a, ll b)
{
    return (((a-b)%mod)+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    if (n==1||m==1)
    {
        cout<<binpow(k,n+m-1);
        return 0;
    }
    ll ans=0;
    for (int i=1;i<=k;++i)
    {
        ans+=(sub(binpow(i,n),binpow(i-1,n))*binpow(k-i+1,m))%mod;
        ans%=mod;
        //cout<<sub(binpow(i,n),binpow(i-1,n))<<" "<<binpow(k-i+1,m)<<"\n";
    }
    cout<<ans;
    return 0;
}