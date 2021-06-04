#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+7;
int tin[N], tout[N], rem[N], t, ans;
set<array<int,2>> s;
vector<int> e1[N],e2[N];

void eulerDfs(int c)
{
    tin[c]=++t;
    for (int i : e2[c])
        eulerDfs(i);
    tout[c]=++t;
}

void dfs(int c)
{
    rem[c]=0;
    if (s.upper_bound({tout[c],c})!=s.end()&&tin[(*s.upper_bound({tout[c],c}))[1]]<tin[c])
    {
        rem[c]=(*s.upper_bound({tout[c],c}))[1];
        s.erase({tout[rem[c]],rem[c]});
        s.insert({tout[c],c});
    }
    else if (!(s.lower_bound({tout[c],c})!=s.begin()&&tin[c]<tin[(*--s.lower_bound({tout[c],c}))[1]]))
        s.insert({tout[c],c});
    ans=max(ans,(int)s.size());
    for (int i : e1[c])
        dfs(i);
    if (s.count({tout[c],c}))
        s.erase({tout[c],c});
    if (rem[c])
        s.insert({tout[rem[c]],rem[c]});
}

void solve()
{
    int n,x;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        e1[i].clear();
        e2[i].clear();
    }
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        e1[x].push_back(i);
    }
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        e2[x].push_back(i);
    }
    t=0;
    eulerDfs(1);
    ans=0;
    s.clear();
    dfs(1);
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}