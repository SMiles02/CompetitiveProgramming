#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res*a)%mod;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,a,b;
    cin>>n;
    ll factorial[1000001];
    factorial[0]=1;
    for (int i=1;i<1000001;++i)
    {
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
    }
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        cout<<(((factorial[a]*binpow(factorial[b],mod-2))%mod)*binpow(factorial[a-b],mod-2))%mod<<"\n";
    }
    return 0;
}