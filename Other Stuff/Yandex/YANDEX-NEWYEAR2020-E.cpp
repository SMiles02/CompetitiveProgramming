#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,int> parent;
map<int,vector<int>> edges;
map<int,int> heights;
pair<int,int> lowest={0,1};
map<int,int> numberOfChildren;

void dfs(int cur, int height)
{
    numberOfChildren[cur]=1;
    heights[cur]=height;
    int k=sz(edges[cur]);
    if (k==1)
    {
        if (lowest.first<height)
        {
            lowest.first=height;
            lowest.second=cur;
        }
        return;
    }
    for (int i=0;i<k;++i)
    {
        if (edges[cur][i]!=parent[cur])
        {
            parent[edges[cur][i]]=cur;
            dfs(edges[cur][i],height+1);
            numberOfChildren[cur]+=numberOfChildren[edges[cur][i]];
        }
    }
    return;
}

void rootDFS()
{
    numberOfChildren[1]=1;
    heights[1]=0;
    int k=sz(edges[1]);
    for (int i=0;i<k;++i)
    {
        parent[edges[1][i]]=1;
        dfs(edges[1][i],1);
        numberOfChildren[1]+=numberOfChildren[edges[1][i]];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    rootDFS();
    for (int i=1;i<=n;++i)
    {
        cout<<i<<" "<<numberOfChildren[i]<<"\n";
    }
    return 0;
}