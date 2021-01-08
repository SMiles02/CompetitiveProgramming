#include <bits/stdc++.h>
using namespace std;

bitset<20> edges[20];
int dp[(1<<20)];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        --x;--y;
        edges[x][y]=edges[y][x]=1;
    }
    for (int i=1;i<(1<<n);++i)
    {
        dp[i]=1;
        for (int j=0;j<n;++j)
            if (i&(1<<j))
                for (int k=j+1;k<n;++k)
                    if (i&(1<<k))
                        if (!edges[j][k])
                            dp[i]=1000000;
        for (int j=(i-1)&i;j;j=(j-1)&i)
            dp[i]=min(dp[i],dp[j]+dp[i^j]);
    }
    cout<<dp[(1<<n)-1];
    return 0;
}