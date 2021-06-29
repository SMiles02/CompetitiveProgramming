#include <bits/stdc++.h>
using namespace std;
 
const int N = 3003;
int p[N];
long long dp[N][N];
 
void solve(int i, int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, k=-1;
    dp[i][m]=1e18;
    for (int j=optL;j<=min(m,optR);++j)
        if (dp[i-1][j-1]+1LL*(p[m]-p[j-1])*(p[m]-p[j-1])<dp[i][m])
        {
            dp[i][m]=dp[i-1][j-1]+1LL*(p[m]-p[j-1])*(p[m]-p[j-1]);
            k=j;
        }
    solve(i,l,m-1,optL,k);
    solve(i,m+1,r,k,optR);
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        p[i]+=p[i-1];
        dp[0][i]=1e18;
    }
    for (int i=1;i<=k;++i)
        solve(i,1,n,1,n);
    cout<<dp[k][n];
    return 0;
}