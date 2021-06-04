#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 998244353;
ll dp[1001][1001];

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

ll mul(ll a, ll b)
{
    return (a*b)%mod;
}

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,a,b,g;
    ll ans;
    cin>>n>>k>>a>>b>>g;
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<=n;++j)
        {
            if (j>0)
                dp[i][j]+=dp[i-1][j-1]*g;
            dp[i][j]+=dp[i-1][j]*(mod+1-g);
            dp[i][j]%=mod;
        }
    }
    for (int i=1;i<=k;++i)
    {
        ans=0;
        for (int j=0;j<=n;++j)
            ans=add(ans,mul(dp[n][j],binpow(add(mul(a,j),b),i)));
        cout<<ans<<" ";
    }
    return 0;
}