#include <bits/stdc++.h>
using namespace std;

int dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s,t,ans="";
    cin>>s>>t;
    int n=s.size(),m=t.size(),j,x,y;
    for (int k=2;k<=n+m;++k)
        for (int i=1;i<k&&i<=n;++i)
            if (k-i<=m)
            {
                j=k-i;
                if (s[i-1]==t[j-1])
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
                dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
            }
    x=n;y=m;
    while (x>0&&y>0)
    {
        if (dp[x][y]==dp[x-1][y])
        {
            --x;
            continue;
        }
        if (dp[x][y]==dp[x][y-1])
        {
            --y;
            continue;
        }
        ans+=s[x-1];
        --x;--y;
    }
    for (int i=dp[n][m]-1;i+1;--i)
        cout<<ans[i];
    return 0;
}