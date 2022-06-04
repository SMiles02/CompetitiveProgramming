#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1005, mod = 1e9+7;
int dp[N][N];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

void solve()
{
    int n,k,ans=0;
    cin>>n>>k;
    for (int i=0;i<=k;++i)
        for (int j=0;j<=n+1;++j)
            dp[i][j]=0;
    dp[k][0]=1;
    for (int i=k;i>0;--i)
    {
        if ((k-i)&1)
        {
            dp[i-1][n]=dp[i][n];
            for (int j=n-1;j>0;--j)
            {
                dp[i][j]=add(dp[i][j],dp[i][j+1]);
                dp[i-1][j]=dp[i][j];
            }
            dp[i][0]=add(dp[i][0],dp[i][1]);
            ans=add(ans,dp[i][0]);
        }
        else
        {
            dp[i-1][0]=dp[i][0];
            for (int j=1;j<n;++j)
            {
                dp[i][j]=add(dp[i][j],dp[i][j-1]);
                dp[i-1][j]=dp[i][j];
            }
            dp[i][n]=add(dp[i][n],dp[i][n-1]);
            ans=add(ans,dp[i][n]);
        }
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