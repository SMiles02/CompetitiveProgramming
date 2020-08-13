#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[2000][2000];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll ans=n*m;
    string s[n];
    for (int i=0;i<n;++i)
    {
        cin>>s[i];
        for (int j=0;j<m;++j)
            dp[i][j]=2000;
    }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            if (i==0||i+1==n||j==0||j+1==m)
            {
                dp[i][j]=0;
                continue;
            }
            else if (s[i][j]==s[i-1][j]&&s[i][j]==s[i][j-1])
                dp[i][j]=min(dp[i][j],1+min(dp[i-1][j],dp[i][j-1]));
            else
                dp[i][j]=0;
        }
    for (int i=n-1;i>=0;--i)
        for (int j=m-1;j>=0;--j)
        {
            if (i==0||i+1==n||j==0||j+1==m)
                continue;
            else if (s[i][j]==s[i+1][j]&&s[i][j]==s[i][j+1])
                dp[i][j]=min(dp[i][j],1+min(dp[i+1][j],dp[i][j+1]));
            else
                dp[i][j]=0;
        }
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            ans+=dp[i][j];
    cout<<ans;
    return 0;
}