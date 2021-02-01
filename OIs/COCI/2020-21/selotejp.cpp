#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 2e6;
int dp[1001][1024],score[1024];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    string s;
    for (int i=0;i<=n;++i)
        for (int j=0;j<1024;++j)
            dp[i][j]=INF;
    dp[0][0]=0;
    for (int i=0;i<1024;++i)
    {
        if (i&1)
            score[i]=1;
        for (int j=1;j<10;++j)
            if (((1<<j)&i)&&!((1<<(j-1))&i))
                ++score[i];
    }
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        x=0;
        for (int j=0;j<m;++j)
            if (s[j]=='#')
                x+=(1<<j);
        for (int j=x;j;j=(j-1)&x)
            for (int k=0;k<1024;++k)
                dp[i][j]=min(dp[i][j],dp[i-1][k]+__builtin_popcount(j-(j&k))+score[j^x]);
        for (int k=0;k<1024;++k)
            dp[i][0]=min(dp[i][0],dp[i-1][k]+score[x]); 
    }
    int ans=INF;
    for (int i=0;i<1024;++i)
        ans=min(ans,dp[n][i]);
    cout<<ans;
    return 0;
}