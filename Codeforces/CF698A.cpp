#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    int dp[n+1][3];
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        dp[i][0]=min(dp[i-1][0],min(dp[i-1][1],dp[i-1][2]))+1;
        dp[i][1]=101;
        dp[i][2]=101;
        if (k==2||k==3)
        {
            dp[i][1]=min(dp[i-1][0],dp[i-1][2]);
        }
        if (k%2)
        {
            dp[i][2]=min(dp[i-1][0],dp[i-1][1]);
        }
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]));
    return 0;
}