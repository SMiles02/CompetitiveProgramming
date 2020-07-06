#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,c;
    cin>>n;
    int dp[n+1][3];
    dp[0][0]=0;dp[0][1]=0;dp[0][2]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a>>b>>c;
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a;
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b;
        dp[i][2]=max(dp[i-1][1],dp[i-1][0])+c;
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
    return 0;
}