#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
#define f first
#define s second
using namespace std;

bool cmp(pii& a, pii& b)
{
    return a.s > b.s;
}

const int mn = 2e5+1;
const ll INF = 1e18;
ll dist[mn];
vector<array<int,2>> edges[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c;
    ll d;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[a].push_back({b+n,c>>1});
        edges[a+n].push_back({b+n,c});
    }
    for (int i=2;i<=2*n;++i)
        dist[i]=INF;
    priority_queue<pii,vector<pii>,function<bool(pii&,pii&)>> pq(cmp);
    pq.push({1,0});
    while (!pq.empty())
    {
        c=pq.top().f;
        d=pq.top().s;
        pq.pop();
        if (d^dist[c])
            continue;
        for (auto i : edges[c])
            if (d+i[1]<dist[i[0]])
            {
                dist[i[0]]=d+i[1];
                pq.push({i[0],d+i[1]});
            }
    }
    cout<<dist[n<<1];
    return 0;
}