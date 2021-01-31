#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const int mn = 2020, INF = 1e9;
int n,k,a[mn],dp[mn][mn];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=0;i<=n;++i)
        for (int j=1;j<=n;++j)
            dp[i][j]=INF;
    for (int i=2;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+a[i]-a[i-1]);
        //cout<<"i = "<<i<<"\n";
        //for (int j=0;j<=n;++j)
        //    cout<<dp[i][j]<<" ";
        //cout<<"\n";
    }
    cout<<dp[n][k];
    return 0;
}