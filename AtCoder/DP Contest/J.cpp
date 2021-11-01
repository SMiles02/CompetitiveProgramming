#include <bits/stdc++.h>
using namespace std;

const int N = 300;
int a[3];
double dp[N+2][N+2][N+2];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,y,z;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        ++a[k-1];
    }
    dp[0][0][0]=-n;
    for (int i=0;i<=N;++i)
        for (int j=0;j<=N;++j)
            for (int k=0;k<=N&&i+j+k<=n;++k)
            {
                dp[i][j][k]+=n;
                if (i>0)
                    dp[i][j][k]+=dp[i-1][j+1][k]*i;
                if (j>0)
                    dp[i][j][k]+=dp[i][j-1][k+1]*j;
                if (k>0)
                    dp[i][j][k]+=dp[i][j][k-1]*k;
                if (i+j+k>0)
                    dp[i][j][k]/=(i+j+k);
            }
    cout<<fixed<<setprecision(10)<<dp[a[2]][a[1]][a[0]];
    return 0;
}