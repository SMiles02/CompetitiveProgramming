//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn = 405;
const ll INF = 1e18;
int n,m,x,y;
vector<array<int,2>> edges[maxn];
ll dist[maxn][maxn][2],z,ans;
priority_queue<array<ll,3>,vector<array<ll,3>>,greater<array<ll,3>>> q;

void dijkstra(int src)
{
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j)
            for (int k=0;k<2;++k)
                dist[i][j][k]=INF;
    q.push({0,src,0});
    dist[src][0][0]=0;
    dist[src][0][1]=0;
    while (!q.empty())
    {
        z=q.top()[0];
        x=q.top()[1];
        y=q.top()[2];
        q.pop();
        if (dist[x][y][0]<z)
            continue;
        for (auto i : edges[x])
        {
            if (z+i[1]<dist[i[0]][max(i[0],y)][0])
            {
                dist[i[0]][max(i[0],y)][0]=z+i[1];
                q.push({dist[i[0]][max(i[0],y)][0],i[0],max(i[0],y)});
            }
            if (z+i[1]<dist[i[0]][y][1])
                dist[i[0]][y][1]=z+i[1];
        }
    }
    for (int j=1;j<=n;++j)
        for (int k=1;k<=n;++k)
        {
            dist[j][k][1]=min(dist[j][k][1],dist[j][k-1][1]);
            if (dist[j][k][1]<INF)
                ans+=dist[j][k][1];
        }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int a,b,c;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    for (int i=1;i<=n;++i)
        dijkstra(i);
    cout<<ans;
    return 0;
}