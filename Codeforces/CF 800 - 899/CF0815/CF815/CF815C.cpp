#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int c[N], d[N], sub[N];
long long dp[2][N][N], tmp[2][N];
vector<int> e[N];

void dfs(int x)
{
    sub[x]=1;
    dp[0][x][1]=dp[1][x][1]=c[x];
    dp[0][x][0]=0;
    for (int i : e[x])
    {
        dfs(i);
        sub[x]+=sub[i];
        for (int j=0;j<2;++j)
            for (int k=0;k<=sub[x];++k)
                tmp[j][k]=dp[j][x][k];
        for (int j=1;j<=sub[x];++j)
            for (int k=max(sub[i]-sub[x]+j,1);k<=min(sub[i],j);++k)
            {
                dp[0][x][j]=min(dp[0][x][j],tmp[0][j-k]+dp[0][i][k]);
                dp[1][x][j]=min({dp[1][x][j],tmp[1][j-k]+dp[0][i][k],tmp[1][j-k]+dp[1][i][k]-d[i]});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,b,x,ans=0;
    cin>>n>>b;
    cin>>c[1]>>d[1];
    c[1]-=d[1];
    for (int i=2;i<=n;++i)
    {
        cin>>c[i]>>d[i]>>x;
        e[x].push_back(i);
    }
    for (int k=0;k<2;++k)
        for (int i=1;i<=n;++i)
            for (int j=0;j<=n;++j)
                dp[k][i][j]=1e18;
    dfs(1);
    for (int i=0;i<2;++i)
        for (int j=1;j<=n;++j)
            if (dp[i][1][j]<=b)
                ans=max(ans,j);
    cout<<ans;
    return 0;
}