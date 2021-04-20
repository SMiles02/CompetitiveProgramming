#include <bits/stdc++.h>
using namespace std;

int dp[60][262145];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("262144.in", "r", stdin);
    freopen("262144.out", "w", stdout);
    int n,ans=0;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        dp[a[i]][i]=i;
        ans=max(ans,a[i]);
    }
    for (int i=1;i<=n;++i)
        for (int j=a[i]+1;dp[j-1][dp[j-1][i]-1];++j)
        {
            dp[j][i]=dp[j-1][dp[j-1][i]-1];
            ans=max(ans,j);
        }
    cout<<ans;
    return 0;
}