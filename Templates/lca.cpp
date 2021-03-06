#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MAXN = 2e5+1, lg = 19; //maximum number of nodes;
int time, up[MAXN][lg], tin[MAXN], tout[MAXN]; //change 19 to log2(MAXN)+2
vector<int> edges[MAXN];

void dfs(int c, int p)
{
    tin[c]=++time;
    up[c][0] = p;
    for (int i=1;i<lg;++i)
        up[c][i] = up[up[c][i-1]][i-1];
    for (int i : edges[c])
        if (i != p)
            dfs(i,c);
    tout[c]=++time;
}

bool isAncestor(int p, int c) //checking if p is an ancestor of c
{
    if (tin[p]<=tin[c]&&tout[c]<=tout[p])
        return 1;
    return 0;
}

int lca(int u, int v)
{
    if (isAncestor(u,v))
        return u;
    if (isAncestor(v,u))
        return v;
    for (int i=18;i>=0;--i)
        if (!isAncestor(up[u][i],v))
            u=up[u][i];
    return up[u][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    //get nodes/edges stuff
    dfs(1,0);
    tout[0]=++time;
    return 0;
}