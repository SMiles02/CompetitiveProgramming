#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn = 1001, INF = 1e8+69;
int n,m,x,dist[maxn][maxn],y;;
vector<pii> edges[maxn];
priority_queue<pii,vector<pii>,greater<pii>> q;

void dijkstra(int src)
{
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
    freopen("roadhelp.in", "r", stdin);
    freopen("roadhelp.out", "w", stdout);
    cin>>n>>m;
    int a,b,c;
    vector<array<int,3>> v(m);
    for (int i=0;i<m;++i)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
        v[i]={a,b,c};
    }
    for (int i=1;i<=n;++i)
        dijkstra(i);
    for (int i=0;i<m;++i)
    {
        c=0;
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                if (dist[j][v[i][0]]+dist[k][v[i][1]]+v[i][2]==dist[j][k])
                    ++c;
        cout<<(c<<1)<<"\n";
    }
    return 0;
}