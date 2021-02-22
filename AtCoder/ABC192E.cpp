#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int maxn = 1e5+1;
const ll INF = 1e18;
int n,m,x;
vector<array<int,3>> edges[maxn];
ll dist[maxn],y;

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=1;i<=n;++i)
        dist[i]=INF;
    q.push({0,src});
    dist[src]=0;
    while (!q.empty())
    {
        y=q.top().f;
        x=q.top().s;
        q.pop();
        if (dist[x]<y)
            continue;
        for (auto i : edges[x])
            if (((y+i[2]-1)/i[2])*i[2]+i[1]<dist[i[0]])
            {
                dist[i[0]]=((y+i[2]-1)/i[2])*i[2]+i[1];
                q.push({dist[i[0]],i[0]});
            }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    int a,b,c,d,from,to;
    cin>>from>>to;
    while (m--)
    {
        cin>>a>>b>>c>>d;
        edges[a].push_back({b,c,d});
        edges[b].push_back({a,c,d});
    }
    dijkstra(from);
    if (dist[to]==INF)
        dist[to]=-1;
    cout<<dist[to];
    return 0;
}