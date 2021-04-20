#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = -1e18;
ll dp[(1<<20)];

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    int n,h;
    ll ans=-1e18,t;
    cin>>n>>h;
    int a[n][3];
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++j)
            cin>>a[i][j];
    for (int i=1;i<(1<<n);++i)
    {
        if (__builtin_popcount(i)==1)
        {
            for (int j=0;j<n;++j)
                if ((1<<j)==i)
                    dp[i]=a[j][2];
            continue;
        }
        dp[i]=INF;
        for (int j=0;j<n;++j)
            if (i&(1<<j))
                dp[i]=max(dp[i],min(dp[(1<<j)^i]-a[j][1],a[j][2]));
    }
    for (int i=1;i<(1<<n);++i)
    {
        t=0;
        for (int j=0;j<n;++j)
            if (i&(1<<j))
                t+=a[j][0];
        if (t>=h)
            ans=max(ans,dp[i]);
    }
    if (ans<0)
        cout<<"Mark is too tall";
    else
        cout<<ans;
    return 0;
}