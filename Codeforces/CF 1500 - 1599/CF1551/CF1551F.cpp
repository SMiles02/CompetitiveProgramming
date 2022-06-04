#include <bits/stdc++.h>
using namespace std;

const int N = 104, MOD = 1e9+7;
int n,k,x,y,t[N];
vector<int> e[N];

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

void dfs(int c, int p, int h)
{
    ++t[h];
    for (int i : e[c])
        if (i!=p)
            dfs(i,c,h+1);
}

void solve()
{
    int ans=0;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
        e[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if (k==2)
    {
        cout<<((1LL*n*(n-1))/2)%MOD<<"\n";
        return;
    }
    for (int i=1;i<=n;++i)
    {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for (int j=0;j<=n;++j)
            dp[j][0]=1;
        for (int j : e[i])
        {
            dfs(j,i,1);
            for (int l=1;l<=n;++l)
            {
                for (int m=n;m>0;--m)
                    dp[l][m]=add(dp[l][m],mul(dp[l][m-1],t[l]));
                t[l]=0;
            }
        }
        for (int i=1;i<=n;++i)
            ans=add(ans,dp[i][k]);
    }
    cout<<ans<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}