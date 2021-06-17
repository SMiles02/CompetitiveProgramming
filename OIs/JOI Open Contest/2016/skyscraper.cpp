#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
  
const int N = 105, MOD = 1e9+7;
int dp[N][N][1005][3];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,ans=0;
    cin>>n>>x;
    if (n==1)
    {
        cout<<1;
        return 0;
    }
    int a[n+1];
    for (int i=0;i<n;++i)
        cin>>a[i];
    a[n]=0;
    sort(a,a+n+1);
    dp[0][0][0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=0;k<=x;++k)
                for (int l=0;l<3;++l)
                {
                    // if (i==2&&j==1&&k==1&&l==1)
                    // {
                    //     cout<<"hi!\n";
                    //     cout<<dp[i][j][k][l]<<"\n";
                    // }
                    //merge two together
                    if (k>=((j+1)*2-l)*(a[i]-a[i-1]))
                        dp[i][j][k][l]=add(dp[i][j][k][l],mul(dp[i-1][j+1][k-((j+1)*2-l)*(a[i]-a[i-1])][l],j));
                    //new comp (non-end)
                    if (k>=((j-1)*2-l)*(a[i]-a[i-1])&&n-i-1+l>=0)
                        dp[i][j][k][l]=add(dp[i][j][k][l],mul(dp[i-1][j-1][k-((j-1)*2-l)*(a[i]-a[i-1])][l],n-i-1+l));
                    //new comp (end)
                    if (k>=((j-1)*2-l+1)*(a[i]-a[i-1])&&n-i-1+l>=0&&l>0)
                        dp[i][j][k][l]=add(dp[i][j][k][l],mul(dp[i-1][j-1][k-((j-1)*2-l+1)*(a[i]-a[i-1])][l-1],3-l));
                    //extend to non-end
                    if (k>=(j*2-l)*(a[i]-a[i-1]))
                        dp[i][j][k][l]=add(dp[i][j][k][l],mul(dp[i-1][j][k-(j*2-l)*(a[i]-a[i-1])][l],j*2));
                    //extend to end
                    if (k>=(j*2-l+1)*(a[i]-a[i-1])&&l>0)
                        dp[i][j][k][l]=add(dp[i][j][k][l],mul(dp[i-1][j][k-(j*2-l+1)*(a[i]-a[i-1])][l-1],3-l));
                }
    cout<<dp[2][1][2][0]<<"\n";
    for (int i=0;i<=x;++i)
        ans=add(ans,dp[n][1][i][2]);
    cout<<ans;
    return 0;
}