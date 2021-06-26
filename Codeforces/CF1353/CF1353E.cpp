#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int onePrefix[1000001];
int dp[1000000][3];


void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i=1;i<=n;++i)
    {
        if (s[i-1]=='1')
            onePrefix[i]=onePrefix[i-1]+1;
        else
            onePrefix[i]=onePrefix[i-1];
    }
    if (s[0]=='0')
    {
        dp[0][0]=0;
        dp[0][1]=1;
        dp[0][2]=0;
    }
    else
    {
        dp[0][0]=1;
        dp[0][1]=0;
        dp[0][2]=1;
    }
    for (int i=1;i<k;++i)
    {
        if (s[i]=='1')
        {
            dp[i][0]=1+onePrefix[i];
            dp[i][1]=onePrefix[i];
            dp[i][2]=1+onePrefix[i];
        }
        else
        {
            dp[i][0]=onePrefix[i];
            dp[i][1]=1+onePrefix[i];
            dp[i][2]=onePrefix[i];
        }
    }
    for (int i=k;i<n;++i)
    {
        if (s[i]=='0')
        {
            dp[i][0]=dp[i-k][0]+onePrefix[i]-onePrefix[i-k+1];
            dp[i][1]=min(dp[i-k][0],dp[i-k][1])+onePrefix[i]-onePrefix[i-k+1]+1;
            dp[i][2]=min(dp[i-k][1],dp[i-k][2])+onePrefix[i]-onePrefix[i-k+1];
        }
        else
        {
            dp[i][0]=dp[i-k][0]+onePrefix[i]-onePrefix[i-k+1]+1;
            dp[i][1]=min(dp[i-k][0],dp[i-k][1])+onePrefix[i]-onePrefix[i-k+1];
            dp[i][2]=min(dp[i-k][1],dp[i-k][2])+onePrefix[i]-onePrefix[i-k+1]+1;
        }
    }
    int ans=min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));
    /**for (int i=0;i<n;++i)
        cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";**/
    for (int i=1;i<k;++i)
        ans=min(ans,onePrefix[n]-onePrefix[n-i]+min(dp[n-i-1][0],min(dp[n-i-1][1],dp[n-i-1][2])));
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    onePrefix[0]=0;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}