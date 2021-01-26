#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define pli pair<ll,int>
#define f first
#define s second
using namespace std;

const int maxn = 5e4+69;
const ll INF = 1e18;
int n,k,x;
vector<pii> edges[maxn];
ll dist[maxn],y;

void dijkstra(int src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (int i=0;i<n;++i)
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

vector<int> v[50], w[50];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        --a[i];
    }
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<k;++j)
            if (!v[j].empty()&&s[a[i]][j]=='1')
            {
                edges[i].push_back({v[j][0],i-v[j][0]});
                if (v[j].size()>1)
                    edges[i].push_back({v[j].back(),i-v[j].back()});
            }
        v[a[i]].push_back(i);
    }
    for (int i=n-1;i>=0;--i)
    {
        for (int j=0;j<k;++j)
            if (!w[j].empty()&&s[a[i]][j]=='1')
            {
                edges[i].push_back({w[j][0],w[j][0]-i});
                if (w[j].size()>1)
                    edges[i].push_back({w[j].back(),w[j].back()-i});
            }
        w[a[i]].push_back(i);
    }
    dijkstra(0);
    if (dist[n-1]==INF)
        dist[n-1]=-1;
    cout<<dist[n-1];
    return 0;
}