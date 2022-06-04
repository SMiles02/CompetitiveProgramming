#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int dp[n][n];
    for (int i=n;i+1;--i)
        for (int j=i;j<n;++j)
        {
            dp[i][j]=j-i+1;
            for (int k=i;k<j;++k)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if (s[k]==s[k+1])
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1);
                if (s[i]==s[j])
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-1);
            }
        }
    cout<<dp[0][n-1];
    return 0;
}