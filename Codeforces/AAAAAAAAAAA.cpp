#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = -1e18;
ll dp[(1<<16)][16];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,f;
    cin>>n>>f;
    ll ans=0;
    int a[n][3];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<3;++j)
            cin>>a[i][j];
        ans=max({ans,1LL*a[i][2]});
    }
    for (int i=1;i<(1<<n);++i)
    {
        if (__builtin_popcount(i)==1)
        {
            for (int j=0;j<n;++j)
            {
                if ((1<<j)==i)
                    dp[i][j]=a[j][2];
                else
                    dp[i][j]=INF;
            }
            continue;
        }
        for (int j=0;j<n;++j)
        {
            dp[i][j]=INF;
            if ((1<<j)&i)
                for (int k=0;k<n;++k)
                    if ((i^(1<<j))&(1<<k)&&a[j][0]<=a[k][0]&&a[k][1]<=a[j][1])
                        dp[i][j]=max({dp[i][j],dp[i^(1<<j)][k]+a[j][2]});
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans;
    return 0;
}