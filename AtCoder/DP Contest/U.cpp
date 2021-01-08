#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[16][16];
ll dp[2][(1<<16)];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>a[i][j];
    for (int i=1;i<(1<<n);++i)
    {
        for (int j=0;j<n;++j)
            if ((1<<j)&i)
            {
                dp[0][i]=dp[0][i^(1<<j)];
                for (int k=j+1;k<n;++k)
                    if ((1<<k)&i)
                        dp[0][i]+=a[j][k];
                break;
            }
        dp[1][i]=max(dp[0][i],0);
        for (int j=(i-1)&i;j;j=(j-1)&i)
            dp[1][i]=max(dp[1][i],dp[1][j]+dp[1][i^j]);
    }
    cout<<dp[1][(1<<n)-1];
    return 0;
}