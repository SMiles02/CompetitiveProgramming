#include <bits/stdc++.h>
#define ll long long
#define int ll
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 1e9+7, mn=2e5+1;
ll fact[mn],im[mn];

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

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll nCr(ll a, ll b)
{
    return (fact[a]*((binpow(fact[a-b],mod-2)*binpow(fact[b],mod-2))%mod))%mod;
}

void solve()
{
    int n,m,k,l,r,mid;
    cin>>n;
    m=3;k=2;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        l=i;r=n-1;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            //cout<<l<<" "<<r<<" "<<mid<<"\n";
            if (a[mid]-a[i]>k)
                r=mid-1;
            else
                l=mid;
            //cout<<a[mid]<<" - "<<a[i]<<"\n";
        }
        //cout<<i<<" "<<l<<"\n";
        if (l-i+1<m)
            continue;
        //cout<<i<<" "<<l<<"!\n";
        //cout<<l-i<<" "<<m-1<<"\n";
        //ans+=nCr(l-i,m-1);
        //ans%=mod;
        ans+=((l-i)*(l-i-1))/2;
    }
    cout<<ans<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fact[0]=1;
    for (int i=1;i<mn;++i)
        fact[i]=(fact[i-1]*i)%mod;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}