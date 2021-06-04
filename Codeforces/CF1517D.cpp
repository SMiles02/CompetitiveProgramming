#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int dp[500][500][11],r[500][500],d[500][500];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m>>x;
    for (int i=0;i<n;++i)
        for (int j=0;j+1<m;++j)
            cin>>r[i][j];
    for (int i=0;i+1<n;++i)
        for (int j=0;j<m;++j)
            cin>>d[i][j];
    if (x&1)
    {
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
                cout<<"-1 ";
            cout<<"\n";
        }
        return 0;
    }
    for (int k=1;k<=x/2;++k)
    {
        for (int i=0;i<n;++i)
            for (int j=0;j<m;++j)
                dp[i][j][k]=INF;
        for (int i=0;i<n;++i)
            for (int j=0;j+1<m;++j)
                dp[i][j][k]=min(dp[i][j][k],dp[i][j+1][k-1]+r[i][j]);
        for (int i=0;i<n;++i)
            for (int j=1;j<m;++j)
                dp[i][j][k]=min(dp[i][j][k],dp[i][j-1][k-1]+r[i][j-1]);
        for (int i=0;i+1<n;++i)
            for (int j=0;j<m;++j)
                dp[i][j][k]=min(dp[i][j][k],dp[i+1][j][k-1]+d[i][j]);
        for (int i=1;i<n;++i)
            for (int j=0;j<m;++j)
                dp[i][j][k]=min(dp[i][j][k],dp[i-1][j][k-1]+d[i-1][j]);
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<m;++j)
            cout<<dp[i][j][x/2]*2<<" ";
        cout<<"\n";
    }
    return 0;
}