#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
using pll = pair<ll,ll>;

vector<pll> edges[(int) 1e5+1];
bool done[(int) 1e5+1];
ll ans[(int) 1e5+1];
int source[(int) 1e5+1];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b>>c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    for (int i=2;i<=n;++i)
        ans[i]=(ll) 1e18+5;
    priority_queue<pll,vector<pll>,greater<pll>> q;
    q.push({1,1});
    while (!q.empty())
    {
        while (!q.empty()&&done[q.top().second])
            q.pop();
        if (q.empty())
            break;
        a=q.top().second;
        q.pop();
        done[a]=1;
        for (auto v : edges[a])
            if (ans[a]+v.second<ans[v.first])
            {
                source[v.first]=a;
                ans[v.first]=ans[a]+v.second;
                q.push({ans[v.first],v.first});
            }
    }
    if (!done[n])
    {
        cout<<-1;
        return 0;
    }
    a=n;
    vector<int> v;
    while (a!=1)
    {
        v.push_back(a);
        a=source[a];
    }
    cout<<"1 ";
    while (sz(v))
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    return 0;
}