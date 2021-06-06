#include <bits/stdc++.h>
using namespace std;

const int N = 104, X = 5005, mod = 1e9+7;
int dp[N][N][X];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x;
    cin>>n>>x;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    a[0]=0;
    dp[0][0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<=x;++k)
            {
                //open & close a group of size 1
                if (k>=j*(a[i]-a[i-1]))
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][j][k-j*(a[i]-a[i-1])]);
                //add to an existing group
                if (k>=j*(a[i]-a[i-1])&&j>0)
                    dp[i][j][k]=add(dp[i][j][k],mul(dp[i-1][j][k-j*(a[i]-a[i-1])],j));
                //open a new group
                if (j>0&&k>=(j-1)*(a[i]-a[i-1]))
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][j-1][k-(j-1)*(a[i]-a[i-1])]);
                //close a group
                if (k>=(j+1)*(a[i]-a[i-1]))
                    dp[i][j][k]=add(dp[i][j][k],mul(dp[i-1][j+1][k-(j+1)*(a[i]-a[i-1])],j+1));
            }
    int ans = 0;
    for (int i=0;i<=x;++i)
        ans=add(ans,dp[n][0][i]);
    cout<<ans;
    return 0;
}