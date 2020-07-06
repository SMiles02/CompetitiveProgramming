#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<int> edges[1001];
set<pair<int,int>> extras;
vector<int> components;
bool done[1001];

void dfs(int cur, int last)
{
    done[cur]=1;
    for (auto v : edges[cur])
    {
        if (done[v])
        {
            if (v!=last)
                extras.insert({min(cur,v),max(cur,v)});
        }
        else
            dfs(v,cur);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            components.push_back(i);
            dfs(i,0);
        }
    cout<<sz(components)-1<<"\n";
    for (int i=1;i<sz(components);++i)
    {
        cout<<(*extras.begin()).first<<" "<<(*extras.begin()).second<<" "<<components[i]<<" "<<components[i-1]<<"\n";
        extras.erase(extras.begin());
    }
    return 0;
}