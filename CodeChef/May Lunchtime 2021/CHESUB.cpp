#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+1, K = 101;
const ll INF = -1e18;
int a[N];
ll p[N], dp[K][N];

void solve(int i, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, k=-1;
    ll best = INF;
    for (int j=min(optR,m);j>=optL;--j)
        if (dp[i-1][j-1]+(p[m]-p[j-1])*i>=best)
        {
            best=dp[i-1][j-1]+(p[m]-p[j-1])*i;
            k=j;
        }
    dp[i][m]=best;
    //cout<<m<<": "<<best<<"\n";
    solve(i,l,m-1,optL,k);
    solve(i,m+1,r,k,optR);
}

void testCase()
{
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        p[i]=p[i-1]+a[i];
    for (int i=1;i<=k;++i)
    {
        for (int j=0;j<=n;++j)
            dp[i][j]=INF;
        solve(i,1,n,1,n);
        dp[i][0]=INF;
        for (int j=1;j<=n;++j)
            dp[i][j]=max(dp[i][j-1],dp[i][j]);
        // for (int j=1;j<=n;++j)
        //     cout<<dp[i][j]<<" ";
        // cout<<"\n";
    }
    cout<<dp[k][n]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        testCase();
    return 0;
}