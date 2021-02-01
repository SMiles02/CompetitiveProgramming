#include <bits/stdc++.h>
#define ll long long
#define int ll
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18;
int n,m,q,x,y;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

void smallCase()
{
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,INF));
    int c[m+1];
    for (int i=1;i<=m;++i)
        cin>>c[i];
    dp[1][1]=0;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            if (i>1)
                dp[i][j]=dp[i-1][j]+c[j];
            if (j>1)
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1LL*i*i);
        }
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        cout<<dp[x][y]<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    if (1LL*n*m<=10000000)
    {
        smallCase();
        return 0;
    }
    int c[m+1];
    for (int i=1;i<=m;++i)
        cin>>c[i];
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        if ((double)x*x*y<=1e18)
            cout<<min(1LL*(x-1)*c[y]+y-1,1LL*(x-1)*c[1]+(y-1)*x*x)<<"\n";
        else
            cout<<1LL*(x-1)*c[y]+y-1<<"\n";
    }
    return 0;
}