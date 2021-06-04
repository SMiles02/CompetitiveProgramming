#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[503][503][2][2];

void solve()
{
    int n,x=0,y=0,z=0;
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<n/2;++i)
    {
        if (s[i]!=s[n-1-i])
            ++y;
        else if (s[i]=='0')
            ++x;
    }
    if ((n&1)&&s[n/2]=='0')
        z=1;
    if (dp[x][y][z][0]>0)
        cout<<"ALICE\n";
    else if (dp[x][y][z][0]<0)
        cout<<"BOB\n";
    else
        cout<<"DRAW\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<503;++i)
        for (int j=0;j<503;++j)
            for (int k=0;k<2;++k)
                for (int l=0;l<2;++l)
                    dp[i][j][k][l]=INF;
    dp[0][0][0][0]=0;
    dp[0][0][0][1]=0;
    for (int i=0;i<=500;++i)
        for (int j=0;j<=500;++j)
            for (int k=0;k<2;++k)
                for (int l=1;l>=0;--l)
                {
                    if (l==0&&!(j==0))
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i][j][k][1]);
                    if (i>0)
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i-1][j+1][k][0]+1);
                    if (j>0)
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i][j-1][k][0]+1);
                    if (k>0)
                        dp[i][j][k][l]=min(dp[i][j][k][l],dp[i][j][0][0]+1);
                    dp[i][j][k][l]*=-1;
                }
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}