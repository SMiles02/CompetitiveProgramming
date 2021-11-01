#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 401;
const ll INF = 1e18;
int a[N];
ll p[N], dp[N][N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[i]=p[i-1]+a[i];
    }
    for (int i=n;i;--i)
    {
        dp[i][i]=0;
        for (int j=i+1;j<=n;++j)
        {
            dp[i][j]=INF;
            for (int k=i;k<j;++k)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+p[j]-p[i-1]);
        }
    }
    cout<<dp[1][n];
    return 0;
}