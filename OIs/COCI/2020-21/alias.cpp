#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<string,int>
#define pli pair<ll,string>
#define f first
#define s second
using namespace std;

const int maxn = 2e5+7;
const ll INF = 1e18;
int n,m;
set<string> st;
map<string,vector<pii>> edges;
map<string,ll> dist;
string x;
ll y;

void dijkstra(string src)
{
    priority_queue<pli,vector<pli>,greater<pli>> q;
    for (auto i : st)
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
    cin>>n>>m;
    string a,b;
    int c,q;
    while (m--)
    {
        cin>>a>>b>>c;
        st.insert(a);
        st.insert(b);
        edges[a].push_back({b,c});
    }
    cin>>q;
    while (q--)
    {
        cin>>a>>b;
        dijkstra(a);
        if (dist[b]==INF)
            cout<<"Roger\n";
        else
            cout<<dist[b]<<"\n";
    }
    return 0;
}