#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans[200001];
int sub[200001],n,u,v;
vector<int> edges[200001];

void dfs(int c, int p, int h)
{ 
    sub[c]=1;
    ans[1]+=h;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c,h+1);
            sub[c]+=sub[i];
        }
}

void dfs2(int c, int p)
{
    ans[c]=ans[p]+n-2*sub[c];
    for (int i : edges[c])
        if (i!=p)
            dfs2(i,c);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0,0);
    for (int i : edges[1])
        dfs2(i,1);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}