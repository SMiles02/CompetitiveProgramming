#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dp[1][0]=1;
    for (int i=2;i<=n;++i)
    {
        dp[i][0]=dp[i-1][0];
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        dp[i][2]=dp[i-1][1]+dp[i-1][2];
    }
    cout<<dp[n][2];
    return 0;
}