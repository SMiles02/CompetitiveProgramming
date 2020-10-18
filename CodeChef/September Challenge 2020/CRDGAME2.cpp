#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9 + 7;
ll f[1000001];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, (b>>1));
    res*=res;
    res%=mod;
    if (b&1)
        return (res * a)%mod;
    return res;
}

void solve()
{
    ll n,m=0,k=0,x;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        if (x>m)
        {
            m=x;
            k=1;
        }
        else if (x==m)
            ++k;
    }
    //cout<<binpow(2,n-k+1)<<" "<<(k-k/2)<<"\n";
    if (k&1)
        cout<<(binpow(2,n-k)*binpow(2,k))%mod<<"\n";
    else
        cout<<(binpow(2,n-k)*((mod+binpow(2,k)-((((f[k]*binpow(f[k/2],mod-2))%mod)*binpow(f[k/2],mod-2))%mod))%mod))%mod<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    f[0]=1;
    for (int i=1;i<1000001;++i)
        f[i]=(f[i-1]*i)%mod;
    while (n--)
        solve();
    return 0;
}