#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1, INF = 1e9+7;
ll mn[N],mx[N],dp[N][2];

ll min(ll x, ll y)
{
    if (x>y)
        return y;
    return x;
}

ll max(ll x, ll y)
{
    if (x<y)
        return y;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        mn[i]=INF;
        mx[i]=-INF;
    }
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        mn[y]=min(mn[y],x);
        mx[y]=max(mx[y],x);
    }
    for (int i=1;i<=n;++i)
    {
        if (mn[i]==INF)
        {
            mn[i]=mn[i-1];
            mx[i]=mx[i-1];
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1];
            continue;
        }
        dp[i][0]=min(dp[i-1][0]+abs(mx[i]-mn[i-1]),dp[i-1][1]+abs(mx[i]-mx[i-1]));
        dp[i][1]=min(dp[i-1][0]+abs(mn[i]-mn[i-1]),dp[i-1][1]+abs(mn[i]-mx[i-1]));
        dp[i][0]+=mx[i]-mn[i];
        dp[i][1]+=mx[i]-mn[i];
        //cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    cout<<min(dp[n][0]+abs(mn[n]),dp[n][1]+abs(mx[n]));
    return 0;
}