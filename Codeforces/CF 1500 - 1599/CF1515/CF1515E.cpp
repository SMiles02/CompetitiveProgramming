#include <bits/stdc++.h>
using namespace std;

const int N = 403;
int mod, dp[N][N], tp[N], f[N], calc[N][N];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int C(int n, int k)
{
    return mul(f[n],binpow(mul(f[n-k],f[k]),mod-2));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n>>mod;
    tp[0]=f[0]=1;
    for (int i=1;i<N;++i)
    {
        dp[i][i]=tp[i-1];
        tp[i]=add(tp[i-1],tp[i-1]);
        f[i]=mul(f[i-1],i);
    }
    for (int i=1;i<N;++i)
        for (int j=0;j<=i;++j)
            calc[i][j]=C(i,j);
    for (int i=2;i<=n;++i)
        for (int j=1;j<i;++j)
            for (int k=1;k<j;++k)
                dp[i][j]=add(dp[i][j],mul(dp[i-k-1][j-k],mul(tp[k-1],calc[j][k])));
    int ans = 0;
    for (int i=1;i<=n;++i)
        ans=add(ans,dp[n][i]);
    cout<<ans;
    return 0;
}