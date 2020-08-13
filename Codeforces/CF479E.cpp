#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[5002][5002],mod=1e9+7;

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int sub(int a, int b)
{
    a-=b;
    if (a<0)
        a+=mod;
    return a;
}

void rangeUpdate(int i, int x, int y, int k)
{
    dp[i][x]=add(dp[i][x],k);
    dp[i][y]=sub(dp[i][y],k);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,k,ans=0;
    cin>>n>>a>>b>>k;
    ++dp[0][a];
    --dp[0][a+1];
    for (int i=0;i<k;++i)
    {
        for (int j=1;j<b;++j)
        {
            dp[i][j]=add(dp[i][j-1],dp[i][j]);
            rangeUpdate(i+1,max(1,2*j-b+1),j,dp[i][j]);
            rangeUpdate(i+1,j+1,b,dp[i][j]);
        }
        dp[i][b]=add(dp[i][b],dp[i][b-1]);
        for (int j=b+1;j<=n;++j)
        {
            dp[i][j]=add(dp[i][j-1],dp[i][j]);
            rangeUpdate(i+1,b+1,j,dp[i][j]);
            rangeUpdate(i+1,j+1,min(2*j-b-1,n)+1,dp[i][j]);
        }
    }
    for (int i=1;i<=n;++i)
    {
        dp[k][i]=add(dp[k][i],dp[k][i-1]);
        ans=add(ans,dp[k][i]);
    }
    cout<<ans;
    return 0;
}