#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF = 1e9;

void solve()
{
    int n;
    cin>>n;
    bool b[n+1];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    int dp[n+1][2];
    for (int i=0;i<=n;++i)
    {
        dp[i][0]=INF;
        dp[i][1]=INF;
    }
    dp[0][0]=0;
    dp[1][1]=dp[0][0]+b[1];
    dp[1][0]=dp[0][1];
    for (int i=2;i<=n;++i)
    {
        dp[i][1]=min(dp[i][1],min(dp[i-1][0]+b[i],dp[i-2][0]+b[i-1]+b[i]));
        dp[i][0]=min(dp[i][0],min(dp[i-1][1],dp[i-2][1]));
    }
    cout<<min(dp[n][0],dp[n][1])<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}