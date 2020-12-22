#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,t;
    ll tot;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>x;
        tot=0;
        for (int j=1;j<=k;++j)
            dp[i][j]=dp[i-1][j];
        for (int j=1;j<=x;++j)
        {
            cin>>t;
            tot+=t;
            for (int J=j;J<=k;++J)
                dp[i][J]=max(dp[i][J],dp[i-1][J-j]+tot);
        }
    }
    cout<<dp[n][k];
    return 0;
}