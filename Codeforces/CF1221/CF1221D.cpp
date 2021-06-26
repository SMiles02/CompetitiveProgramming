#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

int a[300001];
int b[300001];
ll dp[300001][3];

void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i]>>b[i];
    for (int i=1;i<=n;++i)
    {
        for (int x=0;x<3;++x)
        {
            dp[i][x]=1000000000000000000;
            for (int y=0;y<3;++y)
                if (a[i]+x!=a[i-1]+y)
                    dp[i][x]=min(dp[i][x],dp[i-1][y]+x*b[i]);
        }
    }
    cout<<min(dp[n][0],min(dp[n][1],dp[n][2]))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0]=-2;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}