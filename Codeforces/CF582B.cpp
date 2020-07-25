#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int o[301];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,t,ans=0;
    cin>>n>>t;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        ++o[a[i]];
    }
    int dp1[n];
    int dp2[n];
    for (int i=0;i<n;++i)
    {
        dp1[i]=1;
        for (int j=0;j<i;++j)
            if (a[j]<=a[i])
                dp1[i]=max(dp1[i],dp1[j]+1);
    }
    for (int i=n-1;i+1;--i)
    {
        dp2[i]=1;
        for (int j=i+1;j<n;++j)
            if (a[i]<=a[j])
                dp2[i]=max(dp2[i],dp2[j]+1);
    }
    if (t==1)
    {
        for (int i=0;i<n;++i)
            ans=max(ans,dp1[i]);
        cout<<ans;
        return 0;
    }
    for (int i=0;i<n;++i)
        cout<<dp1[i]<<" ";
    cout<<"\n";
    for (int i=0;i<n;++i)
        cout<<dp2[i]<<" ";
    cout<<"\n";
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            for (int k=1;k<301;++k)
                if (a[i]<=k&&k<=a[j])
                    ans=max(ans,dp1[i]+dp2[j]+o[k]*(t-2));
    cout<<ans;
    return 0;
}