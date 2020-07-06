#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
map<int,int> done;

void dfs(int cur)
{
    done[cur]=1;
    int k=sz(edges[cur]);
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
    int n,a,b,ans=0;
    map<int,int> x;
    map<int,int> y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>a>>b;
        if (x[a])
        {
            edges[x[a]].push_back(i);
            edges[i].push_back(x[a]);
        }
        else
        {
            x[a]=i;
        }
        if (y[b])
        {
            edges[y[b]].push_back(i);
            edges[i].push_back(y[b]);
        }
        else
        {
            y[b]=i;
        }
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            ++ans;
            dfs(i);
        }
    }
    cout<<ans-1;
    return 0;
}