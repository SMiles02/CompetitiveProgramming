#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod=1e9+7;
ll fact[1001];

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

ll nCr(int n, int k)
{
    return (fact[n]*binpow((fact[n-k]*fact[k])%mod,mod-2))%mod;
}

ll mult(ll a, ll b)
{
    return (a*b)%mod;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,pos,less=0,more=0,l,r,m;
    cin>>n>>x>>pos;
    fact[0]=1;
    for (int i=1;i<1001;++i)
        fact[i]=(fact[i-1]*i)%mod;
    l=0;r=n;
    while (l<r)
    {
        m=(l+r)/2;
        //cout<<l<<" "<<r<<" "<<m<<"\n";
        if (m==pos)
            l=m+1;
        else if (m<=pos)
        {
            ++less;
            l=m+1;
        }
        else
        {
            ++more;
            r=m;
        }
    }
    if (less>x-1||more>(n-x))
    {
        cout<<"0";
        return 0;
    }
    cout<<mult(mult(nCr(x-1,less),fact[less]),mult(mult(nCr(n-x,more),fact[more]),fact[n-1-more-less]));
    return 0;
}