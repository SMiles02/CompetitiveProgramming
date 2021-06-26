#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 501, INF = 1e9;
int dp[2][mn][mn]; //lastVal, xVal

void solve()
{
    int n,x,k,ans=INF;
    cin>>n>>x;
    for (int i=0;i<mn;++i)
        for (int j=0;j<mn;++j)
            dp[0][i][j]=INF;
    dp[0][0][x]=0;
    for (int c=0;c<n;++c)
    {
        cin>>k;
        for (int i=0;i<mn;++i)
            for (int j=0;j<mn;++j)
                dp[1][i][j]=INF;
        for (int i=0;i<mn;++i)
            for (int j=0;j<mn;++j)
            {
                if (i<=k&&dp[0][i][j]<INF)
                {
                    dp[1][k][j]=min(dp[0][i][j],dp[1][k][j]);
                    //cout<<k<<" "<<j<<" "<<i<<" "<<j<<"\n";
                }
                if (j<k&&i<=j)
                {
                    dp[1][j][k]=min(dp[0][i][j]+1,dp[1][j][k]);
                    //cout<<j<<" "<<k<<" "<<i<<" "<<j<<"\n";
                }
            }
        //cout<<"\n";
        for (int i=0;i<mn;++i)
            for (int j=0;j<mn;++j)
                dp[0][i][j]=dp[1][i][j];
        /**for (int i=0;i<6;++i)
        {
            for (int j=0;j<6;++j)
                cout<<dp[0][i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";**/
    }
    for (int i=0;i<mn;++i)
        for (int j=0;j<mn;++j)
            ans=min(ans,dp[0][i][j]);
    if (ans==INF)
        ans=-1;
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