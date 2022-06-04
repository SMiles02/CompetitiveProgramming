#include <bits/stdc++.h>
using namespace std;

const int N = 402, INF = 1e9;
int a[N][N];

void solve()
{
    int n,m,cur,endHere,ans=INF,startNew;
    cin>>n>>m;
    char c;
    vector<vector<vector<int>>> dp(2,vector<vector<int>>(m+1,vector<int>(m+1,INF)));
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>c;
            a[i][j]=(c-'0');
        }
    for (int j=1;j<=m;++j)
    {
        cur=3-a[2][j]-a[3][j]-a[4][j];
        for (int k=j+1;k<=m;++k)
        {
            if (k>j+2)
                dp[0][j][k]=cur+3-a[2][k]-a[3][k]-a[4][k];
            cur+=a[2][k]+a[3][k]+a[4][k]+1-a[1][k];
        }
    }
    for (int i=5;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            startNew=3-a[i-2][j]-a[i-1][j]-a[i][j];
            cur=1-a[i][j];
            endHere=0;
            for (int k=j+1;k<=m;++k)
            {
                if (k>j+2)
                {
                    ans=min(ans,endHere+dp[0][j][k]);
                    dp[1][j][k]=min(dp[0][j][k]+cur+1-a[i][k],startNew+3-a[i-2][k]-a[i-1][k]-a[i][k]);
                }
                cur+=a[i][k];
                endHere+=1-a[i][k];
                startNew+=a[i-2][k]+a[i-1][k]+a[i][k]+1-a[i-3][k];
            }
        }
        swap(dp[0],dp[1]);
        for (int j=1;j<=m;++j)
            for (int k=j;k<=m;++k)
                dp[1][j][k]=INF;
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}