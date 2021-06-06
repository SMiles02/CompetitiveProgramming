#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 307;
const ll INF = 1e18;
ll dp[N][N][N][2]; //drops, l, r

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x=0,l,k;
    ll ans=0;
    cin>>n>>m;
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            for (int k=0;k<N;++k)
                dp[i][j][k][0]=dp[i][j][k][1]=INF;
    int a[n+1];
    for (int i=0;i<n;++i)
        cin>>a[i];
    a[n]=0;
    sort(a,a+n+1);
    for (int i=0;i<=n;++i)
        if (a[i]==0)
            x=i;
    for (int i=n;i>0;--i)
    {
        for (l=n;l>=0;--l)
            for (int j=0;j+l<=n;++j)
            {
                k=j+l;
                if (l==i)
                {
                    dp[i][j][k][0]=0;
                    dp[i][j][k][1]=0;
                }
                if (j!=0)
                {
                    dp[i][j][k][0]=min(dp[i][j][k][0], dp[i][j-1][k][0]+(a[j]-a[j-1])*(i-l));
                    dp[i][j][k][1]=min(dp[i][j][k][1], dp[i][j-1][k][0]+(a[k]-a[j-1])*(i-l));
                }
                if (k<n)
                {
                    dp[i][j][k][0]=min(dp[i][j][k][0], dp[i][j][k+1][1]+(a[k+1]-a[j])*(i-l));
                    dp[i][j][k][1]=min(dp[i][j][k][1], dp[i][j][k+1][1]+(a[k+1]-a[k])*(i-l));
                }
            }
        ans=max(ans,1LL*i*m-dp[i][x][x][0]);
    }
    cout<<ans<<"\n";
    return 0;
}