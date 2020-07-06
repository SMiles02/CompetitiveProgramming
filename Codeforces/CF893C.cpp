#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
int k;
vector<int> v={0};
map<int,int> done;

void dfs(int cur)
{
    done[cur]=1;
    k=min(k,v[cur]);
    int s=sz(edges[cur]);
    for (int i=0;i<s;++i)
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
    int n,m,x,y;
    ll ans=0;
    cin>>n>>m;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        v.push_back(x);
    }
    for (int i=0;i<m;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            k=1000000000;
            dfs(i);
            ans+=k;
        }
    }
    cout<<ans;
    return 0;
}