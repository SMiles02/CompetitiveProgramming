#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a,ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

ll min(ll a,ll b)
{
    if (a<b)
    {
        return a;
    }
    return b;
}

void solve()
{
    int n;
    cin>>n;
    ll ab[n][2];
    ll ans=9223372036854775807;
    for (int i=0;i<n;++i)
    {
        cin>>ab[i][0]>>ab[i][1];
    }
    ll dp[2*n];
    dp[0]=max(0,ab[0][0]-ab[n-1][1]);
    for (int i=1;i<n;++i)
    {
        dp[i]=dp[i-1]+max(0,ab[i][0]-ab[i-1][1]);
    }
    dp[n]=dp[n-1]+max(0,ab[0][0]-ab[n-1][1]);
    for (int i=1;i<n;++i)
    {
        dp[n+i]=dp[n+i-1]+max(0,ab[i][0]-ab[i-1][1]);
    }
    /**for (int i=0;i<2*n;++i)
    {
        cout<<"dp["<<i<<"] = "<<dp[i]<<"\n";
    }**/
    for (int i=0;i<n;++i)
    {
        ans=min(ans,ab[i][0]+dp[n+i-1]-dp[i]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}