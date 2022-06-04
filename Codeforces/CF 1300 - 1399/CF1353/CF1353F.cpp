#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll INF = 1000000000000000000;
ll a[100][100];
ll dp[100][100];
ll ans;
int n,m;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

void check(int x, int y)
{
    dp[x][y]=0;
    for (int i=x-1;i>=0;--i)
    {
        if (a[i][y]<a[x][y]-x+i)
            dp[i][y]=INF;
        else
            dp[i][y]=dp[i+1][y]+a[i][y]-a[x][y]+x-i;
    }
    for (int i=x+1;i<n;++i)
    {
        if (a[i][y]<a[x][y]-x+i)
            dp[i][y]=INF;
        else
            dp[i][y]=dp[i-1][y]+a[i][y]-a[x][y]+x-i;
    }
    for (int j=y-1;j>=0;--j)
    {
        if (a[x][j]<a[x][y]-y+j)
            dp[x][j]=INF;
        else
            dp[x][j]=dp[x][j+1]+a[x][j]-a[x][y]+y-j;
    }
    for (int j=y+1;j<m;++j)
    {
        if (a[x][j]<a[x][y]-y+j)
            dp[x][j]=INF;
        else
            dp[x][j]=dp[x][j-1]+a[x][j]-a[x][y]+y-j;
    }
    for (int i=x-1;i>=0;--i)
        for (int j=y-1;j>=0;--j)
        {
            if (a[i][j]<a[x][y]-x+i-y+j)
                dp[i][j]=INF;
            else
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+a[i][j]-a[x][y]+x-i+y-j;
        }
    for (int i=x+1;i<n;++i)
        for (int j=y+1;j<m;++j)
        {
            if (a[i][j]<a[x][y]-x+i-y+j)
                dp[i][j]=INF;
            else
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j]-a[x][y]+x-i+y-j;
        }
    ans=min(ans,dp[0][0]+dp[n-1][m-1]);
}

void solve()
{
    ans=INF;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            check(i,j);
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