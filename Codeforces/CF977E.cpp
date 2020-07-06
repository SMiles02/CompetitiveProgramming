#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> done;
map<int,vector<int>> edges;
int hasAllTwos;

void dfs(int cur)
{
    done[cur]=1;
    int k=sz(edges[cur]);
    if (k!=2)
    {
        hasAllTwos=0;
    }
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans=0,u,v;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            hasAllTwos=1;
            dfs(i);
            if (hasAllTwos)
            {
                ++ans;
            }
        }
    }
    cout<<ans;
    return 0;
}