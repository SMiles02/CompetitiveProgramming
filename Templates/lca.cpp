#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 2e5+1, L = 19; //maximum number of nodes;
int timer, up[N][L], tin[N], tout[N]; //change 19 to log2(N)+2
vector<int> e[N];

void dfs(int c, int p)
{
    tin[c]=++timer;
    up[c][0] = p;
    for (int i=1;i<L;++i)
        up[c][i] = up[up[c][i-1]][i-1];
    for (int i : e[c])
        if (i != p)
            dfs(i,c);
    tout[c]=++timer;
}

bool isAncestor(int p, int c) //checking if p is an ancestor of c
{
    return (tin[p]<=tin[c]&&tout[c]<=tout[p]);
}

int lca(int u, int v)
{
    if (isAncestor(u,v))
        return u;
    if (isAncestor(v,u))
        return v;
    for (int i=L-1;i>=0;--i)
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
    tout[0]=++timer;
    return 0;
}