#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,ans=1;
    cin>>n;
    int s[n+1];
    int dp[n+1];
    for (int i=1;i<=n;++i)
    {
        dp[i]=1;
        cin>>s[i];
    }
    for (int i=n;i>0;--i)
    {
        for (int j=2*i;j<=n;j+=i)
            if (s[i]<s[j])
                dp[i]=max(dp[i],dp[j]+1);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<"\n";
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