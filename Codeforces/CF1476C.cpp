#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n;
    cin>>n;
    int a[n],b[n],c[n];
    ll ans=0,dp[n][2];
    for (int i=0;i<n;++i)
        cin>>c[i];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    dp[0][0]=abs(a[1]-b[1]),dp[0][1]=-INF;
    for (int i=1;i+1<n;++i)
    {
        ans=max(ans,max(dp[i-1][0],dp[i-1][1])+c[i]+1);
        dp[i][0]=abs(a[i+1]-b[i+1]);
        if (a[i+1]^b[i+1])
            dp[i][1]=c[i]-abs(a[i+1]-b[i+1])+max(dp[i-1][0],dp[i-1][1])+1;
        else
            dp[i][1]=0;
    }
    ans=max(ans,max(dp[n-2][0],dp[n-2][1])+c[n-1]+1);
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