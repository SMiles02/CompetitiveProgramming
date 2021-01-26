#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int mod = 1e9+7;

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

ll f[1001];

ll C(int n, int k)
{
    return (f[n]*binpow((f[k]*f[n-k])%mod,mod-2))%mod;
}

void solve()
{
    int n,k,x=0,y=0;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for (int i=1;i<=k;++i)
        if (a[i]==a[k])
            ++y;
    for (int i=1;i<=n;++i)
        if (a[i]==a[k])
            ++x;
    cout<<C(x,y)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    f[0]=1;
    for (int i=1;i<1001;++i)
        f[i]=(f[i-1]*i)%mod;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}