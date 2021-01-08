#include <bits/stdc++.h>
using namespace std;

double dp[3000][3000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    double d;
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>d;
        dp[i][0]=dp[i-1][0]*(1-d);
        for (int j=1;j<=i;++j)
            dp[i][j]=(dp[i-1][j-1]*d)+(dp[i-1][j]*(1-d));
    }
    for (int j=n/2+2;j<=n;++j)
        dp[n][j]+=dp[n][j-1];
    cout<<fixed<<setprecision(10)<<dp[n][n];
    return 0;
}