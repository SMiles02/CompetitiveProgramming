#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1, L = 19;
int n, tin[N*4], tout[N*4], low[N], t, up[20][N*4], dp[N*4][2];
vector<array<int,2>> e[N];
vector<int> bctE[N*4];
bitset<N*4> d1, d2, d3, d4;
set<int> s[N];
map<int,int> eN[N];
string ans = "B";

void dfs(int c, int p, int k)
{
    d1[c]=1;
    tin[c]=low[c]=++t;
    for (auto i : e[c])
        if (i[1]!=p)
        {
            if (d1[i[0]])
                low[c]=min(low[c],tin[i[0]]);
            else
            {
                dfs(i[0],i[1],k);
                low[c]=min(low[c],low[i[0]]);
                if (tin[c]<low[i[0]])
                {
                    s[c].insert(i[0]);
                    s[i[0]].insert(c);
                }
            }
        }
}

void build(int c, int g)
{
    d2[c]=1;
    bctE[c].push_back(g);
    bctE[g].push_back(c);
    for (auto i : e[c])
        if (!d2[i[0]])
        {
            if (s[c].count(i[0]))
            {
                bctE[c].push_back(i[0]);
                bctE[i[0]].push_back(c);
                build(i[0],++t);
            }
            else
                build(i[0],g);
        }
}

void bctDfs(int c, int p)
{
    d3[c]=1;
    up[0][c]=p;
    for (int i=1;i<L;++i)
        up[i][c]=up[i-1][up[i-1][c]];
    tin[c]=++t;
    for (int i : bctE[c])
        if (i!=p)
            bctDfs(i,c);
    tout[c]=++t;
}

bool isAncestor(int x, int y)
{
    if (tin[x]<=tin[y]&&tout[y]<=tout[x])
        return 1;
    return 0;
}

int lca(int x, int y)
{
    if (isAncestor(x,y))
        return x;
    if (isAncestor(y,x))
        return y;
    for (int i=L-1;i>=0;--i)
        if (!isAncestor(up[i][x],y))
            x=up[i][x];
    return up[0][x];
}

void ansDfs(int c, int p)
{
    d4[c]=1;
    for (int i : bctE[c])
        if (i!=p)
        {
            ansDfs(i,c);
            dp[c][0]+=dp[i][0];
            dp[c][1]+=dp[i][1];
        }
    if (c<=n&&p<=n)
    {
        if (dp[c][0])
        {
            if (eN[c][p])
                ans[eN[c][p]]='R';
            else
                ans[eN[p][c]]='L';
        }
        else if (dp[c][1])
        {
            if (eN[c][p])
                ans[eN[c][p]]='L';
            else
                ans[eN[p][c]]='R';
        }
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,q,x,y,z;
    cin>>n>>m;
    for (int i=1;i<=m;++i)
    {
        ans+='B';
        cin>>x>>y;
        eN[x][y]=i;
        e[x].push_back({y,i});
        e[y].push_back({x,i});
    }
    for (int i=1;i<=n;++i)
        if (!d1[i])
            dfs(i,-1,i);
    t=n;
    for (int i=1;i<=n;++i)
        if (!d2[i])
            build(i,++t);
    t=0;
    for (int i=1;i<=n;++i)
        if (!d3[i])
            bctDfs(i,0);
    tout[0]=++t;
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        z=lca(x,y);
        ++dp[x][0];
        ++dp[y][1];
        --dp[z][0];
        --dp[z][1];
    }
    for (int i=1;i<=n;++i)
        if (!d4[i])
            ansDfs(i,0);
    for (int i=1;i<=m;++i)
        cout<<ans[i];
    return 0;
}