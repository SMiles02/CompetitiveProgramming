#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn=1e6+7,mod=1e9+7;
ll dp[4][maxn];

ll add(ll a, ll b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

ll mult(ll a, ll b)
{
    return ((a%mod)*(b%mod))%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dp[0][0]=1;
    for (int j=1;j<=n;++j)
    {
        dp[0][j]=mult(dp[0][j-1],8);
        dp[1][j]=add(dp[0][j-1],mult(dp[1][j-1],9));
        dp[2][j]=add(dp[0][j-1],mult(dp[2][j-1],9));
        dp[3][j]=add(mult(dp[3][j-1],10),add(dp[1][j-1],dp[2][j-1]));
    }
    cout<<dp[3][n];
    return 0;
}