//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1005, M = 11, MOD = 998244353;
int dp[N][M][1<<M];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    string s;
    cin>>s;
    s="!"+s;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<M;++j)
            for (int k=0;k<(1<<M);++k)
                dp[i][j][k]=dp[i-1][j][k];
        dp[i][s[i]-'A'][(1<<(s[i]-'A'))]=add(dp[i][s[i]-'A'][(1<<(s[i]-'A'))],1);
        for (int k=0;k<(1<<M);++k)
            dp[i][s[i]-'A'][k]=add(dp[i][s[i]-'A'][k],dp[i-1][s[i]-'A'][k]);
        for (int j=0;j<M;++j)
            for (int k=0;k<(1<<M);++k)
                if ((1<<(s[i]-'A'))&k)
                    dp[i][s[i]-'A'][k]=add(dp[i][s[i]-'A'][k],dp[i-1][j][k^(1<<(s[i]-'A'))]);
    }
    for (int j=0;j<M;++j)
        for (int k=1;k<(1<<M);++k)
            ans=add(ans,dp[n][j][k]);
    cout<<ans;
    return 0;
}