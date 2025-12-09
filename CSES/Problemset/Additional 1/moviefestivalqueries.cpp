#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6+7;
int dp[N][21], a[N];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,ans;
    cin>>n>>q;
    for (int i=1;i<N;++i)
        a[i]=N-1;
    while (n--)
    {
        cin>>x>>y;
        a[x]=min(a[x],y);
    }
    for (int i=0;i<21;++i)
        dp[N-1][i]=N-1;
    for (int i=N-2;i>0;--i)
    {
        a[i]=min(a[i],a[i+1]);
        dp[i][0]=a[i];
        for (int j=1;j<21;++j)
            dp[i][j]=dp[dp[i][j-1]][j-1];
    }
    while (q--)
    {
        cin>>x>>y;
        ans=0;
        for (int i=20;i>=0;--i)
            if (dp[x][i]<=y)
            {
                ans+=1<<i;
                x=dp[x][i];
            }
        cout<<ans<<"\n";
    }
    return 0;
}