#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;

ll mul(ll x, ll y)
{
    return (x*y)%mod;
}

ll f(ll x)
{
    return mul((mod+1)/2,mul(x%mod,(x+1)%mod));
}

ll f(ll l, ll r)
{
    return (f(r)-f(l-1)+mod)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k=1,ans=0;
    cin>>n;
    while (k<=n)
    {
        ans+=f(k,n/(n/k))*((n/k)%mod);
        ans%=mod;
        k=n/(n/k)+1;
    }
    cout<<ans;
    return 0;
}