#include <bits/stdc++.h>
#define ll long long
#define int ll
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7, maxn = 2e5+7;;
ll ans=0;

void add(ll a)
{
    ans+=a;
    if (ans>mod)
        ans-=mod;
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

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0;
    ll third=binpow(3,mod-2);
    cin>>n;
    string s;
    cin>>s;
    int a[n],c[n];
    a[0]=0;
    if (s[0]=='a')
        ++a[0];
    if (s[0]=='?')
        a[0]+=third;
    for (int i=1;i<n;++i)
    {
        a[i]=a[i-1];
        if (s[i]=='?')
            a[i]+=third;
        else if (s[i]=='a')
            ++a[i];
        a[i]%=mod;
    }
    c[n-1]=0;
    if (s[n-1]=='c')
        c[n-1]=1;
    if (s[n-1]=='?')
        c[n-1]=third;
    for (int i=n-2;i+1;--i)
    {
        c[i]=c[i+1];
        if (s[i]=='?')
            c[i]+=third;
        else if (s[i]=='c')
            ++c[i];
        c[i]%=mod;
    }
    for (int i=1;i+1<n;++i)
    {
        if (s[i]=='b')
            add((a[i-1]*c[i+1])%mod);
        else if (s[i]=='?')
            add((((third)*((a[i-1]*c[i+1])%mod)))%mod);
    }
    for (int i=0;i<n;++i)
        if (s[i]=='?')
            ++k;
    cout<<(ans*binpow(3,k))%mod;;
    return 0;
}