#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int mn = 1e5+7;
const ll INF = 1e18;
int x,segTree[mn*4][2],c;;
vector<pii> edges[mn*9];
ll dist[mn*9],y;

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i][0]=segTree[i][1]=l;
        return;
    }
    segTree[i][0]=++c;
    segTree[i][1]=++c;
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    edges[segTree[i][0]].push_back({segTree[i*2+1][0],0});
    edges[segTree[i][0]].push_back({segTree[i*2+2][0],0});
    edges[segTree[i*2+1][1]].push_back({segTree[i][1],0});
    edges[segTree[i*2+2][1]].push_back({segTree[i][1],0});
}

vector<int> v;

void query(int i, int cL, int cR, int l, int r, int j)
{
    if (r<cL||cR<l)
        return;
    if (l<=cL&&cR<=r)
    {
        v.push_back(segTree[i][j]);
        return;
    }
    query(i*2+1,cL,cL+(cR-cL)/2,l,r,j);
    query(i*2+2,cL+(cR-cL)/2+1,cR,l,r,j);
}

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=1;i<=c;++i)
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
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,s,t,x,y,z,w;
    cin>>n>>q>>s;
    c=n;
    build(0,1,n);
    while (q--)
    {
        cin>>t;
        if (t==1)
        {
            cin>>x>>y>>z;
            edges[x].push_back({y,z});
        }
        else if (t==2)
        {
            cin>>x>>y>>z>>w;
            v.clear();
            query(0,1,n,y,z,0);
            for (int i : v)
                edges[x].push_back({i,w});
        }
        else
        {
            cin>>x>>y>>z>>w;
            v.clear();
            query(0,1,n,y,z,1);
            for (int i : v)
                edges[i].push_back({x,w});
        }
    }
    dijkstra(s);
    for (int i=1;i<=n;++i)
    {
        if (dist[i]==INF)
            dist[i]=-1;
        cout<<dist[i]<<" ";
    }
    return 0;
}