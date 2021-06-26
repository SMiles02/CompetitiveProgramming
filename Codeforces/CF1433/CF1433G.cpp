#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

const int maxn = 1001, INF = 1e9;
int n,dist[maxn][maxn],d[maxn][maxn],x,y;
vector<pii> edges[maxn];

void dijkstra(int src)
{
    priority_queue<pii,vector<pii>,greater<pii>> q;
    for (int i=1;i<=n;++i)
        dist[src][i]=INF;
    q.push({0,src});
    dist[src][src]=0;
    while (!q.empty())
    {
        y=q.top().f;
        x=q.top().s;
        q.pop();
        if (dist[src][x]<y)
            continue;
        for (pii i : edges[x])
            if (y+i.s<dist[src][i.f])
            {
                dist[src][i.f]=y+i.s;
                q.push({dist[src][i.f],i.f});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a,b,c,m,k;
    cin>>n>>m>>k;
    int r[k][2];
    vector<pii> allEdges;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
        allEdges.push_back({a,b});
    }
    for (int i=1;i<=n;++i)
        dijkstra(i);
    ll ans=0,cur;
    for (int i=0;i<k;++i)
    {
        cin>>r[i][0]>>r[i][1];
        ans+=dist[r[i][0]][r[i][1]];
    }
    for (pii i : allEdges)
    {
        cur=0;
        for (int j=0;j<k;++j)
            cur+=min(dist[r[j][0]][r[j][1]],min(dist[i.f][r[j][0]],dist[i.s][r[j][0]])+min(dist[i.f][r[j][1]],dist[i.s][r[j][1]]));
        ans=min(ans,cur);
    }
    cout<<ans;
    return 0;
}