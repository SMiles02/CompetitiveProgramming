#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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
    int a[n];
    ll dp[n],ans=0;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=n-1;i+1;--i)
    {
        dp[i]=a[i];
        if (a[i]+i<n)
            dp[i]+=dp[i+a[i]];
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