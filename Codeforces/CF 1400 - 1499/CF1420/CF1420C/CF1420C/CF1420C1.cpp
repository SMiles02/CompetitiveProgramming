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
    int n,q,k;
    cin>>n>>q;
    ll dp[n+1][2];
    dp[0][0]=-INF;
    dp[0][1]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+k);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-k);
    }
    cout<<max(dp[n][0],dp[n][1])<<"\n";
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