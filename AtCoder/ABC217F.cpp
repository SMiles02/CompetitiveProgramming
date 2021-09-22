#include <bits/stdc++.h>
using namespace std;

const int N = 402, MOD = 998244353;
int dp[N][N], f[N];
bitset<N> e[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b)
{
    return mul(a,binpow(b,MOD-2));
}

int C(int n, int k)
{
    return dv(f[n],mul(f[n-k],f[k]));
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    f[0]=1;
    for (int i=1;i<N;++i)
        f[i]=mul(f[i-1],i);
    while (m--)
    {
        cin>>x>>y;
        e[x][y]=1;
        if (y==x+1)
            dp[x][y]=1;
    }
    for (int j=4;j<=n*2;++j)
        for (int i=j-3;i>0;i-=2)
        {
            for (int k=i+1;k<j;k+=2)
                dp[i][j]=add(dp[i][j],mul(C((j-i+1)/2,(j-k)/2),mul(dp[i][k],dp[k+1][j])));
            if (e[i][j])
                dp[i][j]=add(dp[i][j],dp[i+1][j-1]);
        }
    cout<<dp[1][n*2];
    return 0;
}