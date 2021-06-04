#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[1<<20],col[20];
bitset<20> e[20],p,d;
bool bad;

void dfs(int c, int x)
{
    d[c]=1;
    col[c]=x;
    for (int i=0;i<20;++i)
        if (p[i]&&e[c][i])
        {
            if (!d[i])
                dfs(i,3-col[c]);
            else if (col[c]==col[i])
                bad=1;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    ll ans=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        e[--x][--y]=1;
        e[y][x]=1;
    }
    for (int i=0;i<(1<<n);++i)
    {
        for (int j=0;j<n;++j)
        {
            if (i&(1<<j))
                p[j]=1;
            else
                p[j]=0;
            d[j]=0;
        }
        bad=0;
        dp[i]=1;
        for (int j=0;j<20;++j)
            if (p[j]&&!d[j])
            {
                dfs(j,1);
                dp[i]*=2;
            }
        if (bad)
            dp[i]=0;
    }
    for (int i=0;i<(1<<n);++i)
    {
        bad=0;
        for (int j=0;j<n;++j)
            if (((1<<j)&i)==0)
                for (int k=0;k<n;++k)
                    if (((1<<k)&i)==0&&e[j][k])
                        bad=1;
        if (bad)
            continue;
        //cout<<i<<": "<<dp[i]<<"\n";
        ans+=dp[i];
    }
    cout<<ans;
    return 0;
}