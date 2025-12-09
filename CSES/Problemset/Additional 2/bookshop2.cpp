#include <bits/stdc++.h>
using namespace std;
 
int dp[1<<17];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,cur;
    cin>>n>>x;
    int h[n],s[n],k[n];
    for (int i=0;i<n;++i)
        cin>>h[i];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
        cin>>k[i];
    for (int i=0;i<n;++i)
        for (int j=0;k[i];++j)
        {
            cur=min(k[i],1<<j);
            k[i]-=cur;
            for (int l=x;l>=cur*h[i];--l)
                dp[l]=max(dp[l],dp[l-cur*h[i]]+cur*s[i]);
        }
    cout<<dp[x];
    return 0;
}