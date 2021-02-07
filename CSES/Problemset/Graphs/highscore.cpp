#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pil pair<int,ll>
#define f first
#define s second
using namespace std;

bool cmp(pil& a, pil& b)
{
    return (a.s<b.s);
}

const int mn = 2501;
const ll INF = -1e18;
int n,x;
ll dist[mn][mn],y;
bitset<mn> done;
priority_queue<pil,vector<pil>,function<bool(pil&, pil&)>> pq(cmp);
vector<array<int,2>> edges[mn];

void dijkstra(int c)
{
    for (int i=1;i<=n;++i)
    {
        done[i]=0;
        dist[c][i]=INF;
    }
    dist[c][c]=0;
    pq.push({c,0});
    while (!pq.empty())
    {
        x=pq.top().f;
        y=pq.top().s;
        pq.pop();
        if (done[x])
            continue;
        done[x]=1;
        for (auto i : edges[x])
            if (!done[i[0]]&&y+i[1]>dist[c][i[0]])
            {
                dist[c][i[0]]=y+i[1];
                pq.push({i[0],y+i[1]});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,x,y,z;
    cin>>n>>m;
    vector<int> v;
    while (m--)
    {
        cin>>x>>y>>z;
        if (x^y)
            edges[x].push_back({y,z});
        else
            v.push_back(x);
    }
    for (int i=1;i<=n;++i)
        dijkstra(i);
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            //cout<<i<<" "<<j<<": "<<dist[i][j]<<"\n";
            if (dist[1][i]^INF&&dist[i][n]^INF&&dist[i][j]+dist[j][i]>0)
            {
                cout<<-1;
                return 0;
            }
        }
    for (int i : v)
        if (dist[1][i]^INF&&dist[i][n]^INF)
        {
            cout<<-1;
            return 0;
        }
    cout<<dist[1][n];
    return 0;
}