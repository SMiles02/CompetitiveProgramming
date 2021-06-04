#include <bits/stdc++.h>
using namespace std;

const int N = 5e4+3;
int cur, gp[N], sz[N], to[N], dp[N];
vector<int> e1[N], e2[N], e3[N];
stack<int> s;
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
    gp[c]=g;
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
        {
            dfs2(x,++cur);
            dp[cur]=sz[cur];
        }
    }
    for (int i=1;i<=n;++i)
        for (int j : e1[i])
            if (gp[i]!=gp[j]&&exist[gp[j]].count(gp[i])==0)
            {
                e3[gp[j]].push_back(gp[i]);
                exist[gp[j]].insert(gp[i]);
                ++to[gp[i]];
            }
    for (int i=1;i<=cur;++i)
        if (to[i]==0)
            s.push(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i : e3[x])
        {
            dp[i]+=dp[x];
            if (--to[i]==0)
                s.push(i);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<dp[gp[i]]-1<<"\n";
    return 0;
}