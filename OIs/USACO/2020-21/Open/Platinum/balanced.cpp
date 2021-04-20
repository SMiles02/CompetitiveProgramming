#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 22, mod = 1e9+7;
int dp[N][N][N][2][2];

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
    int n,ans=0;
    cin>>n;
    char c[n+1][n+1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            cin>>c[i][j];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=j;k<=n;++k)
            {
                if (c[i][k]=='.')
                    break;
                dp[i][j][k][0][0]=1;
                
                for (int l=1;l==1;++l)
                    for (int o=1;o<j;++o)
                        for (int q=0;q<2;++q)
                        {
                            for (int m=1;m==1;++m)
                                for (int p=k+1;p<=n;++p)
                                    for (int r=0;r<2;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m==0;++m)
                                for (int p=max(o,j);p<k;++p)
                                    for (int r=0;r==0;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m<2;++m)
                                for (int p=k;p==k;++p)
                                    for (int r=m;r==m;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                        }
                
                for (int l=0;l==0;++l)
                    for (int o=j+1;o<=k;++o)
                        for (int q=0;q==0;++q)
                        {
                            for (int m=1;m==1;++m)
                                for (int p=k+1;p<=n;++p)
                                    for (int r=0;r<2;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m==0;++m)
                                for (int p=max(o,j);p<k;++p)
                                    for (int r=0;r==0;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m<2;++m)
                                for (int p=k;p==k;++p)
                                    for (int r=m;r==m;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                        }

                for (int l=0;l<2;++l)
                    for (int o=j;o==j;++o)
                        for (int q=l;q==l;++q)
                        {
                            for (int m=1;m==1;++m)
                                for (int p=k+1;p<=n;++p)
                                    for (int r=0;r<2;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m==0;++m)
                                for (int p=max(o,j);p<k;++p)
                                    for (int r=0;r==0;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                            for (int m=0;m<2;++m)
                                for (int p=k;p==k;++p)
                                    for (int r=m;r==m;++r)
                                        dp[i][j][k][l][m]=add(dp[i][j][k][l][m],dp[i-1][o][p][q][r]);
                        }
                for (int l=0;l<2;++l)
                    for (int m=0;m<2;++m)
                    {
                        //cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<": "<<dp[i][j][k][l][m]<<"\n";
                        ans=add(ans,dp[i][j][k][l][m]);
                    }
            }
    cout<<ans;
    return 0;
}