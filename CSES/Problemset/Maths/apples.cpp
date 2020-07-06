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
    int n,m;
    cin>>n>>m;
    ll factorial[n+m];
    factorial[0]=1;
    for (int i=1;i<n+m;++i)
    {
        factorial[i]=factorial[i-1]*i;
        factorial[i]%=mod;
        //cout<<factorial[i]<<"\n";
    }
    //cout<<n+m-1<<" "<<m<<" "<<n-1<<"\n";
    cout<<(((factorial[n+m-1]*binpow(factorial[m],mod-2))%mod)*binpow(factorial[n-1],mod-2))%mod<<"\n";
    return 0;
}