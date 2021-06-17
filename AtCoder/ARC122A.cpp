#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7;
int dp[2][100005][2];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

ll mul(ll a, ll b)
{
    return (a*b)%MOD;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    ll ans=0;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dp[0][1][0]=1;
    dp[1][n+1][0]=1;
    for (int i=2;i<=n;++i)
    {
        dp[0][i][0]=add(dp[0][i-1][0],dp[0][i-1][1]);
        dp[0][i][1]=dp[0][i-1][0];
    }
    for (int i=n;i>0;--i)
    {
        dp[1][i][0]=add(dp[1][i+1][0],dp[1][i+1][1]);
        dp[1][i][1]=dp[1][i+1][0];
    }
    for (int i=1;i<=n;++i)
    {
        ans+=mul(a[i],mul(dp[0][i][0],dp[1][i][0]));
        ans-=mul(a[i],mul(dp[0][i][1],dp[1][i][1]));
        ans%=MOD;
        ans+=MOD;
        ans%=MOD;
    }
    cout<<ans;
    return 0;
}