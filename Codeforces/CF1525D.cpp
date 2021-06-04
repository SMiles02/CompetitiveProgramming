#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[5001][5001], a[5001], b[5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k=0;
    cin>>n;
    string s;
    dp[0][0]=0;
    for (int i=0;i<=n;++i)
        for (int j=1;j<=n;++j)
            dp[i][j]=INF;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i])
            b[++k]=i;
    }
    for (int i=1;i<=n;++i)
    {
        if (a[i]==0)
            for (int j=1;j<=k;++j)
            {
                if (i<b[j])
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+b[j]-i);
                else
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+i-b[j]);
            }
        else
            for (int j=1;j<=k;++j)
                dp[i][j]=dp[i-1][j];
    }
    cout<<dp[n][k];
    return 0;
}