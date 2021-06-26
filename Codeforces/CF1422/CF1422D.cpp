#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn = 1e5+7;
const ll INF=1e18;
vector<pii> edges[maxn];
bitset<maxn> done;
ll dist[maxn];

void addEdge(int x, int y, int z)
{
    edges[x].push_back({z,y});
    edges[y].push_back({z,x});
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x1,x2,y1,y2;
    cin>>n>>m;
    cin>>x1>>y1>>x2>>y2;
    addEdge(m,m+1,abs(x1-x2)+abs(y1-y2));
    vector<pair<pii,int>> X(m),Y(m);
    for (int i=0;i<m;++i)
    {
        cin>>X[i].f.f>>X[i].f.s;
        Y[i].f.f=X[i].f.s;
        Y[i].f.s=X[i].f.f;
        X[i].s=i;
        Y[i].s=i;
        addEdge(m,i,min(abs(X[i].f.f-x1),abs(X[i].f.s-y1)));
        addEdge(m+1,i,abs(X[i].f.f-x2)+abs(X[i].f.s-y2));
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i=1;i<m;++i)
    {
        addEdge(X[i-1].s,X[i].s,X[i].f.f-X[i-1].f.f);
        addEdge(Y[i-1].s,Y[i].s,Y[i].f.f-Y[i-1].f.f);
    }
    priority_queue<pii,vector<pii>,greater<pii>> q;
    q.push({0,m});
    for (int i=0;i<=m+1;++i)
        dist[i]=INF;
    dist[m]=0;
    while (!q.empty())
    {
        n=q.top().s;
        q.pop();
        if (done[n])
            continue;
        done[n]=1;
        for (pii i : edges[n])
            if (dist[n]+i.f<dist[i.s])
            {
                dist[i.s]=dist[n]+i.f;
                q.push({dist[i.s],i.s});
            }
    }
    cout<<dist[m+1];
    return 0;
}