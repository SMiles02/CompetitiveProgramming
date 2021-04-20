#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 205;
const ll INF = 1e18;
int md[N*3],l;
ll dp[N][N][N][2];

int d(int x, int y)
{
    return (min(abs(x-y),l-abs(x-y)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=1;
    cin>>n>>l;
    int a[n+1],t[n+1];
    a[0]=t[0]=0;
    for (int i=1;i<=n;++i)
    {
        md[i]=i;
        cin>>a[i];
    }
    for (int i=1;i<=n;++i)
        cin>>t[i];
    for (int i=n+1;i<N*3;++i)
        md[i]=md[i-n-1];
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            for (int k=0;k<N;++k)
                dp[i][j][k][0]=dp[i][j][k][1]=INF;
    dp[1][0][0][0]=0;
    for (int i=1;i<=n+1;++i)
    {
        for (int j=1;j<=n;++j)
            for (int k=0;k<=n;++k)
            {
                dp[i][k][md[k+j]][0]=min({dp[i-1][md[k+1]][md[k+j]][0]+d(a[md[k+1]],a[k]),dp[i-1][md[k+1]][md[k+j]][1]+d(a[md[k+j]],a[k])});
                dp[i][k][md[k+j]][1]=min({dp[i-1][k][md[k+j-1]][1]+d(a[md[k+j]],a[md[k+j-1]]),dp[i-1][k][md[k+j-1]][0]+d(a[md[k+j]],a[k])});
                if (dp[i][k][md[k+j]][0]>t[k])
                    dp[i][k][md[k+j]][0]=INF;
                if (dp[i][k][md[k+j]][1]>t[md[k+j]])
                    dp[i][k][md[k+j]][1]=INF;
            }
        for (int j=1;j<=n;++j)
            for (int k=0;k<=n;++k)
            {
                dp[i][k][md[k+j]][0]=min({dp[i][k][md[k+j]][0],dp[i][md[k+1]][md[k+j]][0]+d(a[md[k+1]],a[k]),dp[i][md[k+1]][md[k+j]][1]+d(a[md[k+j]],a[k])});
                dp[i][k][md[k+j]][1]=min({dp[i][k][md[k+j]][1],dp[i][k][md[k+j-1]][1]+d(a[md[k+j]],a[md[k+j-1]]),dp[i][k][md[k+j-1]][0]+d(a[md[k+j]],a[k])});
            }
    }
    for (int i=1;i<=n+1;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<=n;++k)
                if (min({dp[i][j][k][0],dp[i][j][k][1]})<INF)
                    ans=i;
    cout<<ans-1;
    return 0;
}