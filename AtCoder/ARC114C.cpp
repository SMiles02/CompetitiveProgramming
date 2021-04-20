#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 998244353, N = 5005;
ll p[N],dp[N][4],ans;

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

ll add(ll a, ll b)
{
    return (a+b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    p[0]=1;
    for (int i=1;i<N;++i)
        p[i]=mul(p[i-1],m);
    dp[0][0]=1;
    for (int i=1;i<=m;++i)
    {
        for (int j=1;j<=n;++j)
        {
            dp[j][0]=mul(add(add(dp[j-1][0],dp[j-1][1]),add(dp[j-1][2],dp[j-1][3])),i-1);
            dp[j][1]=add(add(dp[j-1][0],dp[j-1][1]),add(dp[j-1][2],dp[j-1][3]));
            dp[j][2]=mul(add(dp[j-1][0],dp[j-1][2]),m-i);
            dp[j][3]=mul(add(dp[j-1][1],dp[j-1][3]),m-i);
            ans=add(ans,mul(add(dp[j-1][0],dp[j-1][2]),p[n-j]));
        }
    }
    cout<<ans;
    return 0;
}