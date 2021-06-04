#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7, N = 1e5+1;
int dp[N],a[200][200],b[200][200];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

void solve()
{
    int n,m,x,ans=0,s;
    cin>>n>>m>>x;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    if (n<m)
    {
        swap(n,m);
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                b[i][j]=a[j][i];
    }
    else
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                b[i][j]=a[i][j];
    for (int j=1;j<(1<<m);++j)
    {
        for (int i=0;i<N;++i)
            dp[i]=0;
        dp[0]=1;
        for (int i=0;i<n;++i)
        {
            s=0;
            for (int k=0;k<m;++k)
                if ((1<<k)&j)
                    s+=b[i][k];
            for (int k=x;k>=s;--k)
                dp[k]=add(dp[k],dp[k-s]);
        }
        ans=add(ans,dp[x]);
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}