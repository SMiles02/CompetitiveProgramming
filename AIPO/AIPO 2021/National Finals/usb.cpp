#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[25][20005];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u;
    cin>>n;
    cin>>u;
    for(int i=0;i<=u;++i)
        for(int j=0;j<=n;++j)
        {
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (i==1)
                dp[i][j]=j;
            else
            {
                dp[i][j]=INF;
                for(int k=0;k<=j;++k)
                    dp[i][j]=min(dp[i][j], 1+max(dp[i-1][k-1], dp[i][j-k]));
            }
        }
    cout<<dp[u][n];
    return 0;
}