#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int maxn = 4007;
const ll INF = 1e18;
int n,m,x;
vector<pii> edges[maxn];
ll dist[maxn],y;

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=1;i<=2*n;++i)
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
        for (pii i : edges[x])
            if (y+i.s<dist[i.f])
            {
                dist[i.f]=y+i.s;
                q.push({dist[i.f],i.f});
            }
    }
    if (dist[src+n]==INF)
        dist[src+n]=-1;
    cout<<dist[src+n]<<"\n";
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
        edges[a].push_back({b+n,c});
        edges[a+n].push_back({b,c});
        edges[a+n].push_back({b+n,c});
    }
    for (int i=1;i<=n;++i)
        dijkstra(i);
    return 0;
}