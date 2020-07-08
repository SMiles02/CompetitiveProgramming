#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,INF=1e9,cur,curSum;
    cin>>n;
    int ans[n+1],b[n+1],c[n+1];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i)
        cin>>c[i];
    cin>>k;
    int dp[n+1][k+1];
    for (int i=0;i<=k;++i)
        dp[0][i]=INF;
    dp[0][0]=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<=k;++j)
        {
            if (dp[i-1][j]<INF)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=INF;
        }
        curSum=0;
        for (int j=1;curSum+j<=c[i];j<<=1)
        {
            for (int ij=k;ij>=j*b[i];--ij)
                if (dp[i][ij-j*b[i]]<INF)
                    dp[i][ij]=min(dp[i][ij-j*b[i]]+j,dp[i][ij]);
            curSum+=j;
        }
        cur=c[i]-curSum;
        for (int ij=k;ij>=cur*b[i];--ij)
            if (dp[i][ij-cur*b[i]]<INF)
                dp[i][ij]=min(dp[i][ij-cur*b[i]]+cur,dp[i][ij]);
    }
    cout<<dp[n][k]<<"\n";
    cur=k;
    for (int i=n;i;--i)
        for (int j=0;j<20001;++j)
            if (dp[i][cur]-j==dp[i-1][cur-j*b[i]])
            {
                ans[i]=j;
                cur-=j*b[i];
                break;
            }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}