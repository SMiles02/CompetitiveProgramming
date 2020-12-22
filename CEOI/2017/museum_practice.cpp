#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 1e4+1, INF=1e9;
int dp[2][mn][mn],sub[mn],k;
vector<pii> edges[mn];
//dp[0/1][i][j]
//i - parent vertice
//j - number of vertices visited
//0 -> return to i
//1 -> no return to i

void dfs(int c, int p)
{
    sub[c]=1;
    dp[0][c][1]=0;
    dp[1][c][1]=0;
    for (pii i : edges[c])
        if (i.f!=p)
        {
            dfs(i.f,c);
            sub[c]+=sub[i.f];
            for (int j=sub[c];j>1;--j)
                for (int K=max(sub[i.f]+j-sub[c],1);K<=min(sub[i.f],j);++K)
                {
                    dp[0][c][j]=min(dp[0][c][j],dp[0][c][j-K]+dp[0][i.f][K]+2*i.s);
                    dp[1][c][j]=min(dp[1][c][j],min(dp[0][c][j-K]+dp[1][i.f][K]+i.s,dp[1][c][j-K]+dp[0][i.f][K]+2*i.s));
                }
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,a,b,c;
    cin>>n>>k>>x;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    for (int i=0;i<=n;++i)
        for (int j=0;j<=k;++j)
        {
            dp[0][i][j]=INF;
            dp[1][i][j]=INF;
        }
    dfs(x,0);
    cout<<dp[1][x][k];
    return 0;
}