#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[201][201][1001];

int mul(int a, int b)
{
    return (1LL*a*b)%mod;
}

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,ans=0;
    cin>>n>>x;
    int a[n+1];
    dp[0][0][0]=1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    a[0]=0;
    sort(a,a+n+1);
    for (int i=1;i<=n;++i)
        for (int j=0;j<=100;++j)
        {
            for (int k=0;k<=x;++k)
            {
                if (k>=(a[i]-a[i-1])*j)
                {
                    //add to some group
                    dp[i][j][k]=add(dp[i][j][k],mul(dp[i-1][j][k-(a[i]-a[i-1])*j],j));
                    //add new group of size 1 (only 1 element)
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][j][k-(a[i]-a[i-1])*j]);
                }
                
                //open new group
                if (j>0&&k>=(a[i]-a[i-1])*(j-1))
                    dp[i][j][k]=add(dp[i][j][k],dp[i-1][j-1][k-(a[i]-a[i-1])*(j-1)]);
                
                //close some group
                if (k>=(a[i]-a[i-1])*(j+1))
                    dp[i][j][k]=add(dp[i][j][k],mul(dp[i-1][j+1][k-(a[i]-a[i-1])*(j+1)],j+1));
            }
        }
    for (int j=0;j<=x;++j)
        ans=add(ans,dp[n][0][j]);
    cout<<ans;
    return 0;
}