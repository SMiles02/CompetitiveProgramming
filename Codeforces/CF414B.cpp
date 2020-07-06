#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,MOD=1000000007;
    cin>>n>>k;
    ll dp[k][n+1];
    ll ans=0;
    for (int i=1;i<=n;++i)
    {
        dp[0][i]=1;
    }
    for (int j=1;j<k;++j)
    {
        for (int i=1;i<=n;++i)
        {
            dp[j][i]=dp[j-1][i];
            for (int x=2;x*i<=n;++x)
            {
                dp[j][i]+=dp[j-1][x*i];
                dp[j][i]%=MOD;
            }
        }        
    }
    for (int i=1;i<=n;++i)
    {
        ans+=dp[k-1][i];
    }
    cout<<ans%MOD;
    return 0;
}