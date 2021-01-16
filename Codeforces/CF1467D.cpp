#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 5069, mod = 1e9+7;
int dp[mn][mn];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,q,x,y;
    cin>>n>>k>>q;
    int a[n],tot[n];
    ll ans=0;
    for (int i=0;i<n;++i)
    {
        tot[i]=dp[0][i]=1;
        cin>>a[i];
    }
    for (int i=1;i<=k;++i)
    {
        dp[i][0]=dp[i-1][1];
        dp[i][n-1]=dp[i-1][n-2];
        tot[0]=add(tot[0],dp[i][0]);
        tot[n-1]=add(tot[n-1],dp[i][n-1]);
        for (int j=1;j+1<n;++j)
        {
            dp[i][j]=add(dp[i-1][j-1],dp[i-1][j+1]);
            tot[j]=add(tot[j],dp[i][j]);
        }
    }
    for (int i=0;i<n;++i)
        ans=(ans+1LL*tot[i]*a[i])%mod;
    while (q--)
    {
        cin>>x>>y;
        --x;
        ans=((ans+1LL*tot[x]*(y-a[x]))%mod+mod)%mod;
        a[x]=y;
        cout<<ans<<"\n";
    }
    return 0;
}