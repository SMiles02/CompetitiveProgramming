#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7, INF = 1e9;
int n,m,x,dist[18][maxn],dp[(1<<18)][18];
vector<int> edges[maxn];

void bfs(int cur, int src)
{
    queue<int> q;
    for (int i=1;i<=n;++i)
        dist[cur][i]=INF;
    q.push({src});
    dist[cur][src]=0;
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : edges[x])
            if (dist[cur][i]==INF)
            {
                dist[cur][i]=dist[cur][x]+1;
                q.push(i);
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int a,b,ans=INF,k,c[20];
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    cin>>k;
    for (int i=0;i<k;++i)
    {
        cin>>c[i];
        bfs(i,c[i]);
    }
    for (int i=1;i<(1<<k);++i)
    {
        if (__builtin_popcount(i)==1)
        {
            for (int j=0;j<k;++j)
            {
                if (i&(1<<j))
                    dp[i][j]=1;
                else
                    dp[i][j]=INF;
            }
            continue;
        }
        for (int j=0;j<k;++j)
        {
            dp[i][j]=INF;
            if (i&(1<<j))
                for (int K=0;K<k;++K)
                    if ((i^(1<<j))&(1<<K))
                        dp[i][j]=min(dp[i][j],dp[i^(1<<j)][K]+dist[j][c[K]]);
        }
    }
    for (int i=0;i<k;++i)
        ans=min(ans,dp[(1<<k)-1][i]);
    if (ans==INF)
        ans=-1;
    cout<<ans;
    return 0;
}