#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=998244353;

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

int dp[201][3];
int pre[201][3];

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0;
    cin>>n;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (a[0]==-1)
        for (int i=1;i<201;++i)
            dp[i][0]=1;
    else
        dp[a[0]][0]=1;
    for (int i=1;i<201;++i)
        for (int j=0;j<3;++j)
            pre[i][j]=add(pre[i-1][j],dp[i][j]);
    for (int g=1;g<n;++g)
    {
        if (a[g]==-1)
            for (int i=1;i<201;++i)
            {
                dp[i][0]=add(pre[i-1][0],add(pre[i-1][1],pre[i-1][2]));
                dp[i][1]=add(sub(pre[i][0],pre[i-1][0]),add(sub(pre[i][1],pre[i-1][1]),sub(pre[i][2],pre[i-1][2])));
                dp[i][2]=add(sub(pre[200][1],pre[i][1]),sub(pre[200][2],pre[i][2]));
            }
        else
        {
            for (int i=1;i<201;++i)
                for (int j=0;j<3;++j)
                    dp[i][j]=0;
            for (int i=a[g];i<a[g]+1;++i)
            {
                dp[i][0]=add(pre[i-1][0],add(pre[i-1][1],pre[i-1][2]));
                dp[i][1]=add(sub(pre[i][0],pre[i-1][0]),add(sub(pre[i][1],pre[i-1][1]),sub(pre[i][2],pre[i-1][2])));
                dp[i][2]=add(sub(pre[200][1],pre[i][1]),sub(pre[200][2],pre[i][2]));
            }
        }
        for (int i=1;i<201;++i)
            for (int j=0;j<3;++j)
                pre[i][j]=add(pre[i-1][j],dp[i][j]);
    }
    for (int i=1;i<201;++i)
        ans=add(ans,add(dp[i][1],dp[i][2]));
    cout<<ans%mod;
    return 0;
}