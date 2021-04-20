#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<ll,int>
using namespace std;

const int N = 1e6+1;
const ll INF = 1e18;
ll d[N];
vector<int> edges[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v,x;
    ll y;
    cin>>n>>u>>v;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        d[i]=INF;
        cin>>a[i];
    }
    stack<int> s,t;
    for (int i=1;i<=n;++i)
    {
        while (!s.empty()&&a[s.top()]>=a[i])
            s.pop();
        if (!s.empty())
            edges[i].push_back(s.top());
        edges[i].push_back(v);
        s.push(i);
    }
    for (int i=n;i>0;--i)
    {
        while (!t.empty()&&a[t.top()]>=a[i])
            t.pop();
        if (!t.empty())
            edges[i].push_back(t.top());
        t.push(i);
    }
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    d[u]=0;
    pq.push({0,u});
    while (!pq.empty())
    {
        x=pq.top().second;
        y=pq.top().first;
        pq.pop();
        if (d[x]!=y)
            continue;
        for (int i : edges[x])
            if (1LL*a[x]*abs(i-x)+d[x]<d[i])
            {
                d[i]=1LL*a[x]*abs(i-x)+d[x];
                pq.push({d[i],i});
            }
    }
    cout<<d[v];
    return 0;
}