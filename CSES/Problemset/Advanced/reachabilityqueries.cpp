#include <bits/stdc++.h>
using namespace std;

//oops i started but idt i can solve rn

const int N = 5e4+3;
int cur, scc[N], sz[N], to[N], tin[N];
vector<int> e1[N], e2[N], sccE[N];
set<int> exist[N];
bitset<N> d1,d2;

void dfs1(int c)
{
    d1[c]=1;
    for (int i : e1[c])
        if (!d1[i])
            dfs1(i);
    s.push(c);
}

void dfs2(int c, int g)
{
    scc[c]=g;
    ++sz[g];
    d2[c]=1;
    for (int i : e2[c])
        if (!d2[i])
            dfs2(i,g);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        e1[x].push_back(y);
        e2[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!d1[i])
            dfs1(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        if (!d2[x])
            dfs2(x,++cur);
    }
    for (int i=1;i<=n;++i)
        for (int j : e1[i])
            if (scc[i]!=scc[j]&&exist[scc[i]].count(scc[j])==0)
            {
                sccE[scc[i]].push_back(scc[j]);
                exist[scc[i]].insert(scc[j]);
                ++to[scc[j]];
            }
    //toposort
    for (int i=1;i<=cur;++i)
        if (to[i]==0)
            s.push(i);
    return 0;
}