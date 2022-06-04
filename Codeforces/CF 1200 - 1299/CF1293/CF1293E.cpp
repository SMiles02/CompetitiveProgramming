#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<pair<int,int>>> globalEdges;
map<int,pair<int,int>> parent;
map<int,int> heights;

void dfs(int cur, int height)
{
    heights[cur]=height;
    int k=sz(globalEdges[cur]);
    for (int i=0;i<k;++i)
    {
        if (globalEdges[cur][i].first!=parent[cur].first)
        {
            parent[globalEdges[cur][i].first]={cur,globalEdges[cur][i].second};
            dfs(globalEdges[cur][i].first,height+1);
        }
    }
    return;
}

void rootDFS()
{
    int k=sz(globalEdges[2]);
    heights[2]=0;
    for (int i=0;i<k;++i)
    {
        parent[globalEdges[2][i].first]={2,globalEdges[2][i].second};
        dfs(globalEdges[2][i].first,1);
    }
    return;
}

int getAnswer(vector<int> v)
{
    int n=v.size();
    sort(v.begin(), v.end());
    for (int i=0;i<n;++i)
    {
        if (v[i]!=i)
        {
            return i;
        }
    }
    return n;
}

int LCA(int u, int v)
{
    vector<int> vect;
    while (heights[u]>heights[v])
    {
        vect.push_back(parent[u].second);
        u=parent[u].first;
    }
    while (heights[v]>heights[u])
    {
        vect.push_back(parent[v].second);
        v=parent[v].first;
    }
    while (u!=v)
    {
        vect.push_back(parent[v].second);
        v=parent[v].first;
        vect.push_back(parent[u].second);
        u=parent[u].first;
    }
    return getAnswer(vect);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,u,v;
    ll ans=0;
    cin>>n;
    if (n==2)
    {
        cout<<1;
        return 0;
    }
    map<int,int> numberOfEdges;
    vector<pair<int,int>> edgePower;
    map<int,pair<int,int>> edges;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[i]={u,v};
        ++numberOfEdges[u];++numberOfEdges[v];
    }
    for (int i=1;i<n;++i)
    {
        edgePower.push_back({numberOfEdges[edges[i].first]+numberOfEdges[edges[i].second],i});
    }
    sort(edgePower.begin(),edgePower.end());
    for (int i=0;i<n-1;++i)
    {
        globalEdges[edgePower[i].first].push_back({edgePower[i].first,i});
    }
    rootDFS();
    for (int i=1;i<=n;++i)
    {
        for (int j=i+1;j<=n;++j)
        {
            ans+=LCA(i,j);
        }
    }
    cout<<ans;
    return 0;
}