//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii array<ll,2>
using namespace std;

const int N = 1e5+1;
const ll INF = 1e18;
vector<array<int,2>> e[N][2];
ll d[N][2];

void dijkstra(int src, int k)
{
    for (int i=0;i<N;++i)
        d[i][k]=INF;
    d[src][k]=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,src});
    int x;
    ll y;
    while (!pq.empty())
    {
        x=pq.top()[1];
        y=pq.top()[0];
        pq.pop();
        if (d[x][k]!=y)
            continue;
        for (auto i : e[x][k])
            if (y+i[1]<d[i[0]][k])
            {
                d[i[0]][k]=y+i[1];
                pq.push({d[i[0]][k],i[0]});
            }
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z;
    ll mx=0;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y>>z;
        e[x][0].push_back({y,z});
        e[y][1].push_back({x,z});
    }
    dijkstra(1,0);
    dijkstra(n,1);
    vector<pii> v;
    vector<int> ans;
    map<ll,int> mp;
    for (int i=1;i<=n;++i)
        if (d[i][0]+d[i][1]==d[1][1])
        {
            ++mp[d[i][0]];
            v.push_back({d[i][0],i});
        }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        if (mx==i[0]&&mp[i[0]]==1)
            ans.push_back(i[1]);
        for (auto j : e[i[1]][0])
            if (i[0]+j[1]==d[j[0]][0]&&d[j[0]][0]+d[j[0]][1]==d[1][1])
                mx=max(mx,d[j[0]][0]);
    }
    sort(ans.begin(), ans.end());
    cout<<sz(ans)<<"\n";
    for (int i : ans)
        cout<<i<<" ";
    return 0;
}