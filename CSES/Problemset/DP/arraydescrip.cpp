#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,x;
int mod=1000000007;
ll dp[100000][102];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    cin>>x;
    if (x==0)
        for (int i=1;i<=m;++i)
            dp[0][i]=1;
    else
        dp[0][x]=1;
    for (int i=1;i<n;++i)
    {
        cin>>x;
        if (x==0)
            for (int j=1;j<=m;++j)
            {
                if (j==1)
                {
                    if (m==1)
                        dp[i][j]=dp[i-1][j];
                    else
                        dp[i][1]=(dp[i-1][1]+dp[i-1][2])%mod;
                }
                else if (j==m)
                    dp[i][m]=(dp[i-1][m]+dp[i-1][m-1])%mod;
                else
                    dp[i][j]=(dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j-1])%mod;
            }
        else if (x==1)
        {
            if (m==1)
                dp[i][1]=dp[i-1][1];
            else
                dp[i][1]=(dp[i-1][1]+dp[i-1][2])%mod;
        }
        else if (x==m)
            dp[i][m]=(dp[i-1][m]+dp[i-1][m-1])%mod;
        else
            dp[i][x]=(dp[i-1][x]+dp[i-1][x+1]+dp[i-1][x-1])%mod;
    }
    ll ans=0;
    for (int i=1;i<=m;++i)
        ans+=dp[n-1][i];
    cout<<ans%mod;
    return 0;
}