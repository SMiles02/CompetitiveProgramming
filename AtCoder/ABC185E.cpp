#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,j;
    cin>>n>>m;
    int a[n+1],b[m+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            dp[i][j]=max(i,j);
    for (int k=2;k<=n+m;++k)
        for (int i=1;i<=n&&i<k;++i)
            if (k-i<=m)
            {
                j=k-i;
                if (a[i]==b[j])
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i][j]),min(dp[i-1][j]+1,dp[i][j-1]+1));
                else
                    dp[i][j]=min(min(dp[i-1][j-1]+1,dp[i][j]),min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
    cout<<dp[n][m];
    return 0;
}