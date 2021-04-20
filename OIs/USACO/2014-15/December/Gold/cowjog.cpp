#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[100005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int n,t,ans=0,l,r,m,x,y;
    cin>>n>>t;
    ll k;
    dp[0]=2e18;
    for (int i=0;i<n;++i)
    {
        cin>>x>>y;
        k=1LL*y*t+x;
        l=0;r=ans;
        while (l<r)
        {
            m=l+(r-l)/2+1;
            if (dp[m]>=k)
                l=m;
            else
                r=m-1;
        }
        if (l==ans)
            dp[++ans]=k;
        else
            dp[l+1]=max(dp[l+1],k);
    }
    cout<<ans;
    return 0;
}