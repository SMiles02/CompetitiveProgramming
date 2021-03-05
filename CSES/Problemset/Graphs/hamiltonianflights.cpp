#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int dp[(1<<20)][20];
int edges[20][20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        ++edges[--x][--y];
    }
    dp[1][0]=1;
    m=(1<<n);
    for (int i=3;i<m;i+=2)
        for (int j=1;j<n;++j)
            if (i&(1<<j))
                for (int k=0;k<n;++k)
                    if ((i^(1<<j))&(1<<k)&&edges[k][j])
                        dp[i][j]=add(dp[i][j],(1LL*dp[i^(1<<j)][k]*edges[k][j])%mod);
    cout<<dp[(1<<n)-1][n-1];
    return 0;
}