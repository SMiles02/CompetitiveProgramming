#include <bits/stdc++.h>
using namespace std;

const int N = 4001, K = 801, INF = 1e9;
int C[N][N], dp[K][N];

void solve(int i, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, best=INF, k=-1;
    for (int j=optL;j<=min(optR,m);++j)
        if (dp[i-1][j-1]+C[m][j]<best)
        {
            best=dp[i-1][j-1]+C[m][j];
            k=j;
        }
    dp[i][m]=best;
    solve(i,l,m-1,optL,k);
    solve(i,m+1,r,k,optR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int u[n+1][n+1];
    for (int i=1;i<=n;++i)
    {
        u[i][0]=0;
        for (int j=1;j<=n;++j)
        {
            cin>>u[i][j];
            u[i][j]+=u[i][j-1];
        }
    }
    for (int j=1;j<=n;++j)
    {
        C[j][j]=0;
        for (int i=j-1;i>0;--i)
            C[j][i]=C[j-1][i]+u[j][j]-u[j][i-1];
    }
    for (int i=1;i<=n;++i)
        dp[1][i]=C[i][1];
    for (int i=2;i<=k;++i)
        solve(i,1,n,1,n);
    cout<<dp[k][n];
    return 0;
}