#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int INF=-1e6;
int n,m,M,x,a[71][71],dp[70],curDP[71][36][71],temp[70],mod[200];
//pos,taken,mod

void rowDP(int r)
{
    for (int i=0;i<=m;++i)
        for (int j=0;j<=M;++j)
            for (int k=0;k<x;++k)
                curDP[i][j][k]=INF;
    curDP[0][0][0]=0;
    for (int i=1;i<=m;++i)
    {
        curDP[i][0][0]=0;
        for (int j=1;j<=M;++j)
            for (int k=0;k<x;++k)
                curDP[i][j][k]=max(max(curDP[i-1][j][k],curDP[i][j-1][k]),curDP[i-1][j-1][mod[k+x-mod[a[r][i]]]]+a[r][i]);
    }
    for (int i=0;i<x;++i)
        temp[i]=INF;
    for (int i=0;i<x;++i)
        for (int j=0;j<x;++j)
            temp[mod[i+j]]=max(temp[mod[i+j]],dp[i]+curDP[m][M][j]);
    for (int i=0;i<x;++i)
        dp[i]=temp[i];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x;
    M=m/2;
    for (int i=1;i<x;++i)
        dp[i]=INF;
    for (int i=1;i<201;++i)
        mod[i]=i%x;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            cin>>a[i][j];
        rowDP(i);
    }
    cout<<dp[0];
    return 0;
}