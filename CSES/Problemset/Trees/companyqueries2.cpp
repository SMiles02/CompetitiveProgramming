#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int cur,tin[200001],tout[200001],binLift[200001][19],f,g;
vector<int> children[200001];

void dfs(int c)
{
    for (int i=1;i<19;++i)
        binLift[c][i]=binLift[binLift[c][i-1]][i-1];
    tin[c]=++cur;
    for (int i : children[c])
    {
        binLift[i][0]=c;
        dfs(i);
    }
    tout[c]=++cur;
}

bool isAncestor(int p, int c)
{
    if (tin[p]<=tin[c]&&tout[c]<=tout[p])
        return 1;
    return 0;
}

int raise(int x, int y)
{
    for (int i=0;i<19;++i)
        if ((1<<i)&y)
        {
            x=binLift[x][i];
            y^=(1<<i);
        }
    return x;
}

int lca(int u, int v)
{
    if (isAncestor(u,v))
        return u;
    if (isAncestor(v,u))
        return v;
    for (int i=18;i>=0;--i)
        if (!isAncestor(binLift[u][i],v))
            u=binLift[u][i];
    return binLift[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q;
    cin>>n>>q;
    for (int i=2;i<=n;++i)
    {
        cin>>f;
        children[f].push_back(i);
    }
    dfs(1);
    tout[0]=++cur;
    while (q--)
    {
        cin>>f>>g;
        cout<<lca(f,g)<<"\n";
    }
    return 0;
}