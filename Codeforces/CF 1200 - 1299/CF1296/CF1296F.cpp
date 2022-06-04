#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
map<int,int> parent;
map<pair<int,int>,int> edgeNumber;
map<int,int> edgeBeauty;
map<int,int> height;
int isTrue=1;

void dfs(int cur, int h)
{
    height[cur]=h;
    int k=sz(edges[cur]);
    for (int i=0;i<k;++i)
    {
        if (edges[cur][i]!=parent[cur])
        {
            parent[edges[cur][i]]=cur;
            dfs(edges[cur][i],h+1);
        }
    }
    return;
}

void rootDFS()
{
    int k=sz(edges[1]);
    for (int i=0;i<k;++i)
    {
        parent[edges[1][i]]=1;
        dfs(edges[1][i],1);
    }
    return;
}

void LCA(int x, int y, int b)
{
    cout<<"LCA of "<<x<<" & "<<y<<"\n";
    while (height[x]<height[y])
    {
        if (edgeBeauty[edgeNumber[{y,parent[y]}]]<b)
        {
            //cout<<y<<" test "<<edgeBeauty[edgeNumber[{y,parent[y]}]]<<" causes the problem\n";
            isTrue=0;
            return;
        }
        edgeBeauty[edgeNumber[{y,parent[y]}]]=b;
        y=parent[y];
    }
    while (height[x]>height[y])
    {
        if (edgeBeauty[edgeNumber[{x,parent[x]}]]<b)
        {
            //cout<<x<<" causes the problem\n";
            isTrue=0;
            return;
        }
        edgeBeauty[edgeNumber[{x,parent[x]}]]=b;
        x=parent[x];
    }
    while (x!=y)
    {
        if (edgeBeauty[edgeNumber[{x,parent[x]}]]<b)
        {
            isTrue=0;
            return;
        }
        edgeBeauty[edgeNumber[{x,parent[x]}]]=b;
        x=parent[x];
        if (edgeBeauty[edgeNumber[{y,parent[y]}]]<b)
        {
            isTrue=0;
            return;
        }
        edgeBeauty[edgeNumber[{y,parent[y]}]]=b;
        y=parent[y];
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a,b,m,k;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        edgeNumber[{a,b}]=i;
        edgeNumber[{b,a}]=i;
        edgeBeauty[i]=1000000;
    }
    rootDFS();
    cin>>m;
    while (m--)
    {
        cin>>a>>b>>k;
        LCA(a,b,k);
    }
    if (!isTrue)
    {
        cout<<"-1\n";
        return 0;
    }
    for (int i=1;i<n;++i)
    {
        cout<<edgeBeauty[i]<<" ";
    }
    return 0;
}