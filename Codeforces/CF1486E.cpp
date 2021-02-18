#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define a4 pair<pair<ll,int>,pii>
#define f first
#define s second
using namespace std;

const int maxn = 1e5+1;
const ll INF = 2e9;
int n,m,x,y,z;
vector<pii> edges[maxn];
ll d,d0[maxn],d1[maxn][51];

int sq(int s)
{
    return s*s;
}

void dijkstra(int src)
{
    priority_queue<a4,vector<a4>,greater<a4>> q;
    for (int i=1;i<=n;++i)
    {
        d0[i]=INF;
        for (int k=0;k<51;++k)
            d1[i][k]=INF;
    }
    q.push({{0,src},{0,0}});
    d0[src]=0;
    while (!q.empty())
    {
        x=q.top().f.s;
        y=q.top().s.f;
        z=q.top().s.s;
        d=q.top().f.f;
        q.pop();
        if (y==1)
        {
            if (d1[x][z]<d)
                continue;
            for (pii i : edges[x])
                if (d+sq(i.s+z)<d0[i.f])
                {
                    d0[i.f]=d+sq(i.s+z);
                    q.push({{d0[i.f],i.f},{0,0}});
                }
        }
        else
        {
            if (d0[x]<d)
                continue;
            for (pii i : edges[x])
                if (d<d1[i.f][i.s])
                {
                    d1[i.f][i.s]=d;
                    q.push({{d1[i.f][i.s],i.f},{1,i.s}});
                }
        }
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
        edges[b].push_back({a,c});
    }
    dijkstra(1);
    for (int i=1;i<=n;++i)
    {
        if (d0[i]==INF)
            d0[i]=-1;
        cout<<d0[i]<<" ";
    }
    return 0;
}