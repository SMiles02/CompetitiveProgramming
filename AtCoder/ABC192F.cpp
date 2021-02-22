#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = -2e9;
int dp[101][101][101];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,y;
    ll x,ans=1e18;
    cin>>n>>x;
    for (int i=0;i<101;++i)
    {
        for (int j=0;j<101;++j)
            for (int k=0;k<101;++k)
                dp[i][j][k]=INF;
        dp[i][0][0]=0;
    }
    for (int z=0;z<n;++z)
    {
        cin>>y;
        for (int i=1;i<=n;++i)
            for (int j=i;j;--j)
                for (int k=0;k<i;++k)
                    dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][(((k-y)%i)+i)%i]+y);
    }
    for (int i=1;i<=n;++i)
        if (dp[i][i][x%i]>0)
            ans=min({ans,(x-dp[i][i][x%i])/i});
    cout<<ans;
    return 0;
}