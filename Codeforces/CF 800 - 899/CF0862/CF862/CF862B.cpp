#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n;
map<int,vector<int>> edges;
map<int,int> doneEdges;
vector<int> c;
vector<int> d;

void dfs(int x)
{
    for (int i=0;i<sz(edges[x]);++i)
    {
        if (!doneEdges[edges[x][i]])
        {
            if (doneEdges[x]==1)
            {
                d.push_back(edges[x][i]);
                doneEdges[edges[x][i]]=2;
            }
            else
            {
                c.push_back(edges[x][i]);
                doneEdges[edges[x][i]]=1;
            }
            dfs(edges[x][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    int a,b;
    ll ans;
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    c.push_back(1);
    doneEdges[1]=1;
    dfs(1);
    ans=sz(c);
    ans*=sz(d);
    cout<<ans-n+1;
    return 0;
}