#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
using pll = pair<ll,ll>;

ll INF=1e18+5;
vector<pair<int,int>> edges[100001];
ll ans[100001];
bool done[100001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    set<pair<int,int>> s;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
    }
    for (int i=2;i<=n;++i)
        ans[i]=INF;
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({0,1});
    for (int i=1;i<n;++i)
    {
        while (done[q.top().second])
            q.pop();
        a=q.top().second;
        done[a]=1;
        q.pop();
        for (auto v : edges[a])
            if (ans[a]+v.second<ans[v.first])
            {
                ans[v.first]=ans[a]+v.second;
                q.push({ans[v.first],v.first});
            }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}