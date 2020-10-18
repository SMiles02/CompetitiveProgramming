#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = -1e9;
int dp[201][201][201]; //dp[stage][a occurences][changesUsed]

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int j=0;j<201;++j)
        for (int k=0;k<201;++k)
            dp[0][j][k]=INF;
    int n,x;
    cin>>n>>x;
    string s,t;
    cin>>s;
    cin>>t;
    if (t[0]==t[1])
    {
        int c=0;
        for (auto i : s)
            if (i==t[0])
                ++c;
        c=min(c+x,n);
        cout<<(c*(c-1))/2<<"\n";
        return 0;
    }
    dp[0][0][0]=0;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<=200;++j)
            for (int k=0;k<=200;++k)
                dp[i+1][j][k]=dp[i][j][k];
        if (s[i]==t[0])
        {
            for (int j=1;j<=200;++j)
                for (int k=0;k<=200;++k)
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j-1][k]);
        }
        if (s[i]==t[1])
        {
            for (int j=0;j<=200;++j)
                for (int k=0;k<=200;++k)
                    dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+j);
        }
        for (int j=1;j<=200;++j)
            for (int k=1;k<=200;++k)
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j-1][k-1]);
        for (int j=0;j<=200;++j)
            for (int k=1;k<=200;++k)
                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k-1]+j);
    }
    int ans=0;
    for (int j=0;j<=200;++j)
            ans=max(ans,dp[n][j][x]);
    cout<<ans;
    return 0;
}