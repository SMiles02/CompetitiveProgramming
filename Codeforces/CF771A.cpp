#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

map<int,vector<int>> edges;
map<int,int> done;
int goodEdges,isTrue=1,vertices;

void dfs(int cur)
{
    ++vertices;
    done[cur]=1;
    int k=sz(edges[cur]);
    if (k!=goodEdges)
    {
        isTrue=0;
    }
    for (int i=0;i<k;++i)
    {
        if (!done[edges[cur][i]])
        {
            dfs(edges[cur][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1;i<=n;++i)
    {
        if (!done[i])
        {
            goodEdges=sz(edges[i]);
            vertices=0;
            dfs(i);
            if (vertices-1!=goodEdges)
            {
                isTrue=0;
            }
        }
    }
    if (isTrue)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}