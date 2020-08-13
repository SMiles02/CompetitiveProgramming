#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<pair<int,ll>> edges[100000+5];
int used[100000+5],uwu;
ll curValue[100000+5];
map<int,int> edgeUse;
priority_queue<pair<ll,int>> q;
ll tot;

void dfs(int c, int p)
{
    bool entered=1;
    used[c]=0;
    for (auto i : edges[c])
        if (i.first!=p)
        {
            entered=0;
            //cout<<c<<" "<<i.first<<" "<<uwu<<"\n";
            dfs(i.first,c);
            used[c]+=used[i.first];
            ++uwu;
            tot+=i.second*used[i.first];
            //cout<<i.second<<" "<<used[i.first]<<"\n";
            q.push({(i.second-(i.second/2))*used[i.first],uwu});
            //cout<<"inserted {"<<(i.second-(i.second/2))*used[i.first]<<","<<uwu<<"}\n";
            curValue[uwu]=i.second;
            edgeUse[uwu]=used[i.first];
        }
    if (entered)
        used[c]=1;
}

void solve()
{
    int n,u,v,ans=0;
    ll s,w;
    cin>>n>>s;
    for (int i=1;i<=n;++i)
        edges[i].clear();
    for (int i=1;i<n;++i)
    {
        cin>>u>>v>>w;
        edges[u].push_back({v,w});
        edges[v].push_back({u,w});
    }
    q = priority_queue <pair<ll,int>>();
    tot=0;
    uwu=0;
    dfs(1,0);
    pair<ll,int> cur;
    //cout<<tot<<"\n";
    while (tot>s)
    {
        ++ans;
        cur=q.top();
        q.pop();
        //cout<<cur.first<<" "<<cur.second<<"\n";
        tot-=cur.first;
        //cout<<"oldval = "<<curValue[cur.second]<<"\n";
        curValue[cur.second]/=2;
        //cout<<"newval = "<<curValue[cur.second]<<"\n";
        cur.first=(curValue[cur.second]-(curValue[cur.second]/2))*edgeUse[cur.second];
        //cout<<"--> "<<cur.first<<" "<<cur.second<<"\n";
        q.push(cur);
        //cout<<tot<<"\n";
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}