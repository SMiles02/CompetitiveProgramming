#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100001][(1<<7)];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,p,k;
    cin>>n>>p>>k;
    array<int,2> a[n+1];
    int s[n][p];
    for (int i=1;i<=n;++i)
        cin>>a[i][0],a[i][1]=i-1;
    for (int i=0;i<n;++i)
        for (int j=0;j<p;++j)
            cin>>s[i][j];
    sort(a+1,a+n+1,greater<array<int,2>>());
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<(1<<p);++j)
        {
            if (i-__builtin_popcount(j)<=k&&__builtin_popcount(j)<i)
                dp[i][j]=dp[i-1][j]+a[i][0];
            else
                dp[i][j]=dp[i-1][j];
        }
        for (int j=1;j<(1<<p);++j)
            for (int k=0;k<p;++k)
                if (j&(1<<k))
                    dp[i][j]=max(dp[i][j],dp[i-1][j^(1<<k)]+s[a[i][1]][k]);
    }
    cout<<dp[n][(1<<p)-1];
    return 0;
}