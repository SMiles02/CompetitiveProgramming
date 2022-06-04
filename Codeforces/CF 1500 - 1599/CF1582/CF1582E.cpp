//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+3, M = 447;
ll dp[N][M], p[N];

void solve()
{
    int n, ans=1;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>p[i];
        p[i]+=p[i-1];
    }
    for (int i=1;i<M;++i)
        dp[n+1][i]=0;
    dp[n+1][0]=1e18;
    for (int i=n;i>=1;--i)
    {
        for (int j=0;j<M;++j)
            dp[i][j]=dp[i+1][j];
        for (int j=i;j<=n&&j-i+1<M;++j)
            if (p[j]-p[i-1]<dp[j+1][j-i])
            {
                dp[i][j-i+1]=max(dp[i][j-i+1],p[j]-p[i-1]);
                ans=max(ans,j-i+1);
            }
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}