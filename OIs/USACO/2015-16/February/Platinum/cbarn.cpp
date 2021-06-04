#include <bits/stdc++.h>
using namespace std;

const int N = 1004, K = 8;
const long long INF = 1e18;
int n, k, r[N*3];
long long dp[K][N], ans = INF, c[N*3][N*3];

void solve(int i, int d, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, x=-1;
    dp[i][m]=INF;
    for (int j=max(m,optL);j<=optR;++j)
        if (dp[i-1][j+1]+c[m+d][j+d]<dp[i][m])
        {
            x=j;
            dp[i][m]=dp[i-1][j+1]+c[m+d][j+d];
        }
    solve(i,d,l,m-1,optL,x);
    solve(i,d,m+1,r,x,optR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>r[i];
        dp[0][i]=INF;
        r[i+n]=r[i];
    }
    for (int i=1;i<=n*2;++i)
        for (int j=i+1;j<=n*2;++j)
            c[i][j]=c[i][j-1]+(j-i)*r[j];
    for (int i=0;i<n;++i)
    {
        for (int j=1;j<=k;++j)
            solve(j,i,1,n,1,n);
        ans=min(ans,dp[k][1]);
    }
    cout<<ans;
    return 0;
}