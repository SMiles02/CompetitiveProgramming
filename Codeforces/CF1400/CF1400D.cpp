#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp1[3002][3002],dp2[3002][3002];

void solve()
{
    ll ans=0;
    int n;
    cin>>n;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=n+1;++i)
        for (int j=0;j<=n+1;++j)
        {
            dp1[i][j]=0;
            dp2[i][j]=0;
        }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            dp1[i][j]+=dp1[i-1][j];
        ++dp1[i][a[i]];
    }
    for (int i=n;i;--i)
    {
        for (int j=1;j<=n;++j)
            dp2[i][j]+=dp2[i+1][j];
        ++dp2[i][a[i]];
    }
    for (int i=1;i<=n;++i)
        for (int j=i+1;j<=n;++j)
            ans+=dp1[i-1][a[j]]*dp2[j+1][a[i]];
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}