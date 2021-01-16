#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<ll,pii>
#define f first
#define s second
using namespace std;

const int mn = 2e5+1;
const ll INF = 1e18;
ll dist[mn][4];
vector<pii> edges[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y>>z;
        edges[x].push_back({y,z});
        edges[y].push_back({x,z});
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<4;++j)
            dist[i][j]=INF;
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    dist[1][0]=0;
    pq.push({0,{1,0}});
    piii p;
    while (!pq.empty())
    {
        p=pq.top();
        pq.pop();
        if (p.f>dist[p.s.f][p.s.s])
            continue;
        x=p.s.f;
        y=p.s.s;
        for (pii i : edges[x])
        {
            if (dist[x][y]+i.s<dist[i.f][y])
            {
                dist[i.f][y]=dist[x][y]+i.s;
                pq.push({dist[i.f][y],{i.f,y}});
            }
            if (!(y&1)&&dist[x][y]+2*i.s<dist[i.f][y^1])
            {
                dist[i.f][y^1]=dist[x][y]+2*i.s;
                pq.push({dist[i.f][y^1],{i.f,y^1}});
            }
            if (!(y&2)&&dist[x][y]<dist[i.f][y^2])
            {
                dist[i.f][y^2]=dist[x][y];
                pq.push({dist[i.f][y^2],{i.f,y^2}});
            }
        }
    }
    for (int i=2;i<=n;++i)
    {
        if (dist[i][0]<dist[i][3])
            cout<<dist[i][0]<<" ";
        else
            cout<<dist[i][3]<<" ";
    }
    return 0;
}