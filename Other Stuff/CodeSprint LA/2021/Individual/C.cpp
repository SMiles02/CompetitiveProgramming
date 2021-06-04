#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const ll INF = 1e18;
ll dp[101][101][2];

void combine(int a, int b, int c, int d)
{
    if (dp[c][d][0]+1<dp[a][b][0])
    {
        dp[a][b][0]=dp[c][d][0]+1;
        dp[a][b][1]=dp[c][d][1];
    }
    else if (dp[c][d][0]+1==dp[a][b][0])
        dp[a][b][1]+=dp[c][d][1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<101;++i)
        for (int j=0;j<101;++j)
        {
            dp[i][j][0]=INF;
            dp[i][j][1]=0;
        }
    dp[0][0][0]=0;
    dp[0][0][1]=1;
    for (int i=0;i<81;++i)
        for (int j=0;j<81;++j)
        {
            if (i>0)
                combine(i,j,i-1,j+1);
            if (j==1&&i==0)
                combine(i,j,i,j-1);
            if (j==2&&i==0)
                combine(i,j,i,j-2);
            if (j>1)
                combine(i,j,i,j-1);
        }
    int n,x,y;
    cin>>n;
    while (n--)
    {
        cin>>x>>y;
        cout<<dp[y][x][1]<<"\n";
    }
    return 0;
}