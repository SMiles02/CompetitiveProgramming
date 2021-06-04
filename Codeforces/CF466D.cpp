#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[2002][2002];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,h,k;
    cin>>n>>h;
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (k>h)
        {
            cout<<0;
            return 0;
        }
        dp[i][h-k]=dp[i-1][h-k];
        if (h-k>0)
        {
            dp[i][h-k]=add(dp[i][h-k],dp[i-1][h-k-1]);
            dp[i][h-k-1]=add(mul(dp[i-1][h-k-1],h-k),mul(dp[i-1][h-k],h-k));
        }
    }
    cout<<dp[n][0];
    return 0;
}