#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2505, MOD = 1e9+7;
int dp[N][N];
ll a[N], p[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

void solve()
{
    int n,ans=0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]^a[i];
    }
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j)
            dp[i][j]=0;
    dp[0][0]=1;
    for (int i=1;i<=min(n,58);++i)
        for (int j=1;j<=n;++j)
            for (int k=0;k<j;++k)
                if ((p[k]^p[j])%(1LL<<(i-1))==0)
                    dp[i][j]=add(dp[i][j],dp[i-1][k]);
    for (int i=59;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=0;k<j;++k)
                if ((p[k]^p[j])==0)
                    dp[i][j]=add(dp[i][j],dp[i-1][k]);
    for (int i=1;i<=n;++i)
        ans=add(ans,dp[i][n]);
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}