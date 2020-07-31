#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[5001][5001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,j;
    string s,t;
    cin>>s;
    cin>>t;
    n=sz(s);m=sz(t);
    for (int i=0;i<5001;++i)
    {
        dp[0][i]=i;
        dp[i][0]=i;
    }
    for (int k=2;k<=n+m;++k)
        for (int i=1;i<k&&i<=n;++i)
            if (k-i<=m)
            {
                j=k-i;
                if (s[i-1]==t[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                    dp[i][j]=dp[i-1][j-1]+1;
                dp[i][j]=min(dp[i][j],min(dp[i-1][j]+1,dp[i][j-1]+1));
                //cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<"\n";
            }
    cout<<dp[n][m];
    return 0;
}