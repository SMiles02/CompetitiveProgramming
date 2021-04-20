#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mn = 5069, mod = 1e9+7;
int dp[2][mn][mn],tot[mn];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

ll mult(ll a, ll b)
{
    return (a*b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,q,x,y;
    cin>>n>>k>>q;
    int a[n];
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        dp[0][0][i]=dp[1][k][i]=1;
        cin>>a[i];
    }
    for (int i=1;i<=k;++i)
    {
        dp[0][i][0]=dp[0][i-1][1];
        dp[0][i][n-1]=dp[0][i-1][n-2];
        for (int j=1;j+1<n;++j)
            dp[0][i][j]=add(dp[0][i-1][j-1],dp[0][i-1][j+1]);
    }
    for (int i=k-1;i>=0;--i)
    {
        dp[1][i][0]=dp[1][i+1][1];
        dp[1][i][n-1]=dp[1][i+1][n-2];
        for (int j=1;j+1<n;++j)
            dp[1][i][j]=add(dp[1][i+1][j-1],dp[1][i+1][j+1]);
    }
    for (int i=0;i<=k;++i)
        for (int j=0;j<n;++j)
            tot[j]=add(tot[j],mult(dp[0][i][j],dp[1][i][j]));
    for (int i=0;i<n;++i)
        ans=add(ans,mult(tot[i],a[i]));
    while (q--)
    {
        cin>>x>>y;
        --x;
        ans=add(ans,mult(tot[x],add(y,mod-a[x])));
        a[x]=y;
        cout<<ans<<"\n";
    }
    return 0;
}