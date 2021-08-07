#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x,k;
    cin>>n>>x;
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1e9));
    dp[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        for (int j=0;j<i;++j)
            dp[i][j]=dp[i-1][j];
        if (i>=k)
            ++dp[i][i-k];
        for (int j=1;j<=i;++j)
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
    }
    for (int j=0;j<=n;++j)
        if (dp[n][j]>=x)
        {
            cout<<j<<"\n";
            return;
        }
    cout<<"-1\n";
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