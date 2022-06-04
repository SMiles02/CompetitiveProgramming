#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+1, K = 1e5;
bitset<N> dp[201];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,t,y;
    ll x;
    cin>>n>>m;
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>t>>x>>y;
        if (t==1)
        {
            x=(x+K-1)/K;
            for (int j=m;j>=0;--j)
                if (dp[i-1][j])
                    for (int k=j,z=0;z<=y&&k<=m&&dp[i][k]==0;++z,k+=x)
                        dp[i][k]=1;
        }
        else
            for (int j=m;j>=0;--j)
                if (dp[i-1][j])
                    for (ll k=j,z=0;z<=y&&k<=m&&dp[i][k]==0;++z,k=(k*x+K-1)/K)
                        dp[i][k]=1;
    }
    for (int i=1;i<=m;++i)
    {
        if (dp[n][i]==0)
        {
            cout<<"-1 ";
            continue;
        }
        for (int j=0;j<=n;++j)
            if (dp[j][i])
            {
                cout<<j<<" ";
                break;
            }
    }
    return 0;
}