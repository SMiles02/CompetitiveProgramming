#include <bits/stdc++.h>
using namespace std;

const int mn = 5e5+1;
int a[mn],s[mn],e[mn],f[mn],dp[mn][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,cur=0,ans=0;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (f[a[i]]==0)
            s[a[i]]=i;
        e[a[i]]=i;
        ++f[a[i]];
    }
    for (int i=1;i<=n;++i)
    {
        if (s[a[i]]==i)
            dp[e[a[i]]][1]=cur+f[a[i]];
        dp[e[a[i]]][0]=max(dp[e[a[i]]][0],cur+f[a[i]]);
        --f[a[i]];
        cur=max(cur,dp[i][1]);
        ans=max(ans,dp[i][0]);
    }
    cout<<n-ans;
    return 0;
}