#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> to[200001];
vector<int> from[200001];
set<int> undecided[200001];
set<int> s;
set<int> s2;
bool ok=0;

void dfs(int cur)
{
    if (s.find(cur)!=s.end())
        return;
    s.insert(cur);
    int y;
    while (sz(undecided[cur]))
    {
        y=*undecided[cur].begin();
        undecided[cur].erase(y);
        undecided[y].erase(cur);
        to[cur].push_back(y);
        from[y].push_back(cur);
    }
    for (int i : to[cur])
        dfs(i);
}

void dfsTree(int cur)
{
    if (s2.find(cur)!=s2.end())
    {
        ok=1;
        return;
    }
    if (s.find(cur)!=s.end())
        return;
    s.insert(cur);
    s2.insert(cur);
    for (int i : from[cur])
        dfsTree(i);
}

void solve()
{
    s.clear();
    int n,m,t,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        to[i].clear();
        from[i].clear();
    }
    for (int i=0;i<m;++i)
    {
        cin>>t>>x>>y;
        if (t)
        {
            from[x].push_back(y);
            to[y].push_back(x);
        }
        else
        {
            undecided[x].insert(y);
            undecided[y].insert(x);
        }
    }
    for (int i=1;i<=n;++i)
        if (!sz(to[i]))
        {
            dfsTree(i);
            s2.clear();
        }
    if (ok||sz(s)<n)
    {
        cout<<"NO\n";
        //cout<<ok<<" "<<sz(s)<<" "<<n<<"\n";
        return;
    }
    s.clear();
    for (int i=1;i<=n;++i)
        if (!sz(from[i]))
            dfs(i);
    if (sz(s)<n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i)
        for (int j : from[i])
            cout<<i<<" "<<j<<"\n";
    return;
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