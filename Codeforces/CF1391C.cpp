#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1e9+7;

ll factorial(int n)
{
    ll ans=1;
    for (int i=1;i<=n;++i)
    {
        ans*=i;
        ans%=mod;
    }
    return ans+mod;
}

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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    cout<<(factorial(n)-binpow(2,n-1))%mod;
    return 0;
}