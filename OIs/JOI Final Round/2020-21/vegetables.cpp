#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+7;
int a[N];
ll dp[N][2];

ll max(ll x, ll y)
{
    if (x>y)
        return x;
    return y;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    ll ans=1e18;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        dp[i][0]=dp[i-1][0]+max(a[i-1]+1-a[i],0);
    for (int i=n;i;--i)
        dp[i][1]=dp[i+1][1]+max(a[i+1]+1-a[i],0);
    for (int i=1;i<=n;++i)
        ans=min(ans,max(dp[i-1][0],dp[i+1][1])+max(0,max(a[i-1]+1-a[i]-max(0,dp[i][1]-dp[i][0]),a[i+1]+1-a[i]-max(0,dp[i][0]-dp[i][1]))));
    cout<<ans;
    return 0;
}