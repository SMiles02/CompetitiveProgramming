#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN=1e5+11, mod=1e9+7;
int c[MAXN];

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
        return (res * a)%mod;;
    return res;
}

void solve()
{
    int n,m,maxi=0,k;
    cin>>n>>m;
    ll ans=1;
    set<int> s;
    for (int i=1;i<n;++i)
        c[i]=0;
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        s.insert(k);
        maxi=max(maxi,k);
        ++c[k];
    }
    if (n-1!=m)
        return;
    if (sz(s)!=maxi)
    {
        cout<<"0\n";
        return;
    }
    for (int i=2;i<=maxi;++i)
    {
        ans*=binpow(c[i-1],c[i]);
        ans%=mod;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}