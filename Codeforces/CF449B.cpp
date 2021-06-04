#include <bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
using namespace std;

const int N = 2e5+7;
const ll INF = 1e18;
int n,m,k,x,ans,train[N];
vector<array<int,2>> edges[N];
ll dist[N],y;
bitset<N> inUse;

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=1;i<=n;++i)
    {
        if (train[i])
        {
            inUse[i]=1;
            dist[i]=train[i];
            q.push({dist[i],i});
        }
        else
            dist[i]=INF;
    }
    q.push({0,src});
    dist[src]=0;
    while (!q.empty())
    {
        y=q.top().first;
        x=q.top().second;
        q.pop();
        if (dist[x]<y)
            continue;
        if (train[x]&&inUse[x])
            --ans;
        for (auto i : edges[x])
        {
            if (y+i[1]<=dist[i[0]])
                inUse[i[0]]=0;
            if (y+i[1]<dist[i[0]])
            {
                dist[i[0]]=y+i[1];
                q.push({dist[i[0]],i[0]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    int a,b,c;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    ans=k;
    while (k--)
    {
        cin>>a>>b;
        if (train[a])
            train[a]=min(train[a],b);
        else
            train[a]=b;
    }
    dijkstra(1);
    cout<<ans;
    return 0;
}