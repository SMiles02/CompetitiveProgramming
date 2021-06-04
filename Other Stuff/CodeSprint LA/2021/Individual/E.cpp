#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int N = 102, INF = 1e9;
int n,m,x,y,z,dist[N][N];
vector<array<int,3>> e[N];

void dijkstra(int src)
{
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
    for (int i=0;i<N;++i)
        for (int j=0;j<N;++j)
            dist[i][j]=INF;
    for (int i=0;i<N;++i)
    {
        q.push({0,src,i});
        dist[src][i]=0;
    }
    while (!q.empty())
    {
        x=q.top()[1];
        y=q.top()[2];
        z=q.top()[0];
        q.pop();
        if (dist[x][y]<z)
            continue;
        for (auto i : e[x])
            if (y+i[1]<N&&z+i[2]<dist[i[0]][y+i[1]])
            {
                dist[i[0]][y+i[1]]=z+i[2];
                q.push({dist[i[0]][y+i[1]],i[0],y+i[1]});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t,f,a;
    cin>>n>>t>>f;
    int h[n+1];
    for (int i=1;i<=n;++i)
        cin>>h[i];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>a;
            if (h[i]>=h[j])
                e[i].push_back({j,0,a});
            else
                e[i].push_back({j,h[j]-h[i],a});
        }
    dijkstra(1);
    if (dist[t][f]==INF)
        dist[t][f]=-1;
    cout<<dist[t][f];
    return 0;
}