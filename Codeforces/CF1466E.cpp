#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 5e5+7, mod = 1e9+7;
int tot[60], powers[60];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

void solve()
{
    int n,cur,ans=0;
    cin>>n;
    ll x[n+1];
    for (int j=0;j<60;++j)
        tot[j]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>x[i];
        for (int j=0;j<60;++j)
            if (x[i]&(1LL<<j))
                ++tot[j];
    }
    for (int i=1;i<=n;++i)
    {
        cur=0;
        for (int j=0;j<60;++j)
        {
            if (x[i]&(1LL<<j))
                cur=add(cur,(powers[j]*n)%mod);
            else
                cur=add(cur,(powers[j]*tot[j])%mod);
        }
        for (int j=0;j<60;++j)
            if (x[i]&(1LL<<j))
                ans=add(ans,(((powers[j]*tot[j])%mod)*cur)%mod);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    powers[0]=1;
    for (int i=1;i<60;++i)
        powers[i]=(powers[i-1]*2)%mod;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}