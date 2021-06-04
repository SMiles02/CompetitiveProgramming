#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int N = 1e5+7;
int n;
int dp[N][4][2], m[N];

int mul(int a, int b)
{
    return (1LL*a*b)%n;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,t=0;
    cin>>n>>a>>b;
    for (int i=1;i<=n;++i)
    {
        m[i]=uniform_int_distribution<int>(1,1000000000)(rng);
        t^=m[i];
    }
    dp[1][0][0]=1;
    dp[1][0][1]=m[1];
    dp[1][1][0]=1;
    dp[1][1][1]=m[1];
    dp[n][2][0]=1;
    dp[n][2][1]=0;
    dp[n][3][0]=1;
    dp[n][3][1]=0;
    for (int i=2;i<n;++i)
    {
        dp[i][0][0]=mul(dp[i-1][0][0],a);
        dp[i][0][1]=dp[i-1][0][1]^m[dp[i][0][0]];
        dp[i][1][0]=mul(dp[i-1][1][0],binpow(a,n-2));
        dp[i][1][1]=dp[i-1][1][1]^m[dp[i][1][0]];
    }
    for (int i=n-1;i>1;--i)
    {
        dp[i][2][0]=mul(dp[i+1][2][0],b);
        dp[i][2][1]=dp[i+1][2][1]^m[dp[i][2][0]];
        dp[i][3][0]=mul(dp[i+1][3][0],binpow(b,n-2));
        dp[i][3][1]=dp[i+1][3][1]^m[dp[i][3][0]];
    }
    for (int i=1;i<n;++i)
        for (int j=0;j<2;++j)
            for (int k=2;k<4;++k)
                if ((dp[i][j][1]^dp[i+1][k][1])==t&&(mul(dp[i][j][0],a)==dp[i+1][k][0]||mul(dp[i][j][0],b)==dp[i+1][k][0]||mul(dp[i][k][0],a)==dp[i+1][j][0]||mul(dp[i][k][0],a)==dp[i+1][j][0]))
                {
                    cout<<"Yes\n";
                    for (int l=1;l<=i;++l)
                        cout<<dp[l][j][0]<<" ";
                    for (int l=i+1;l<=n;++l)
                        cout<<dp[l][k][0]<<" ";
                    return 0;
                }
    cout<<"No\n";
    return 0;
}