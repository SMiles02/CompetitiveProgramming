#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n][n];
    int dp[n][2];
    dp[0][0]=0;
    dp[0][1]=0;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
    for (int i=1;i<n;++i)
    {
        if (a[i][0]>a[0][i])
        {
            dp[i][0]=min(dp[i-1][0],dp[i-1][1]+1);
            dp[i][1]=min(dp[i-1][0]+1,dp[i-1][1]+2);
        }
        else
        {
            dp[i][0]=min(dp[i-1][0]+2,dp[i-1][1]+1);
            dp[i][1]=min(dp[i-1][0]+1,dp[i-1][1]);
        }
        dp[i][0]=min(dp[i][0],dp[i][1]+1);
        dp[i][1]=min(dp[i][1],dp[i][0]+1);
        //cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    cout<<dp[n-1][0]<<"\n";
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