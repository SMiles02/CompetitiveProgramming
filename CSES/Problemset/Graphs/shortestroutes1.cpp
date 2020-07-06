#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll INF=1e18+5;
vector<pair<int,int>> edges[100001];
ll ans[100001];
bool done[100001];

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

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
    s.insert({0,1});
    ans[1]=0;
    while (!s.empty())
    {
        a=(*(s.begin())).second;
        s.erase(s.begin());
        for (auto v : edges[a])
            if (ans[a]+v.second<ans[v.first])
            {
                s.erase({ans[v.first],v.first});
                ans[v.first]=ans[a]+v.second;
                s.insert({ans[v.first],v.first});
            }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}