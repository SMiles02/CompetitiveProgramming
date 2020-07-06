#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[101][101][101][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<101;++i)
        for (int j=0;j<101;++j)
            for (int k=0;k<101;++k)
                for (int l=0;l<2;++l)
                    dp[i][j][k][l]=101;
    dp[0][0][0][0]=0;
    dp[0][0][0][1]=0;
    int n,x;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        if (x==0)
        {
            dp[i][0][i][1]=dp[i-1][0][i-1][1];
            dp[i][i][0][0]=dp[i-1][i-1][0][0];
            for (int j=1;j<=i;++j)
            {
                dp[i][j][i-j][0]=min(dp[i-1][j-1][i-j][1]+1,dp[i-1][j-1][i-j][0]);
                dp[i][i-j][j][1]=min(dp[i-1][i-j][j-1][0]+1,dp[i-1][i-j][j-1][1]);
            }
        }
        else if (x%2)
        {
            dp[i][0][i][1]=dp[i-1][0][i-1][1];
            for (int j=1;j<=i;++j)
                dp[i][i-j][j][1]=min(dp[i-1][i-j][j-1][0]+1,dp[i-1][i-j][j-1][1]);
        }
        else
        {
            dp[i][i][0][0]=dp[i-1][i-1][0][0];
            for (int j=1;j<=i;++j)
                dp[i][j][i-j][0]=min(dp[i-1][j-1][i-j][1]+1,dp[i-1][j-1][i-j][0]);
        }
    }
    cout<<min(dp[n][n/2][n-(n/2)][0],dp[n][n/2][n-(n/2)][1]);
    return 0;
}