#include <bits/stdc++.h>
using namespace std;

int dp[1501][1501];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,s,m,k,l=1,r=1e9+1,mid,x,y;
    cin>>n>>s>>m>>k;
    int a[n+1], b[n+1], p[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<=n;++i)
        b[i]=i+1;
    while (s--)
    {
        cin>>x>>y;
        b[y]=min(b[y],x);
    }
    for (int i=n-1;i>=0;--i)
        b[i]=min(b[i],b[i+1]);
    p[0]=0;
    while (l<r)
    {
        mid=l+(r-l)/2;
        for (int i=1;i<=n;++i)
        {
            if (a[i]<=mid)
                p[i]=p[i-1]+1;
            else
                p[i]=p[i-1];
            dp[i][0]=0;
            for (int j=1;j<=m;++j)
                dp[i][j]=max(dp[i-1][j],dp[b[i]-1][j-1]+p[i]-p[b[i]-1]);
        }
        x=0;
        for (int j=1;j<=m;++j)
            x=max(x,dp[n][j]);
        if (x>=k)
            r=mid;
        else
            l=mid+1;
    }
    if (l>1e9)
        l=-1;
    cout<<l;
    return 0;
}