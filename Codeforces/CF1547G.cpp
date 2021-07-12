#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int cur, scc[N], sz[N], to[N], dp[N];
vector<int> e1[N], e2[N], sccE[N];
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
    scc[c]=g;
    ++sz[g];
    d2[c]=1;
    for (int i : e2[c])
        if (!d2[i])
            dfs2(i,g);
}

void solve()
{
    int n,m,x,y;
    cur=0;
    cin>>n>>m;
    for (int i=0;i<=n*2;++i)
    {
        e1[i].clear();
        e2[i].clear();
        exist[i].clear();
        sccE[i].clear();
        to[i]=0;
        sz[i]=0;
        dp[i]=0;
        d1[i]=d2[i]=0;
    }
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
        {
            if (scc[i]!=scc[j])
            {
                sccE[scc[i]].push_back(scc[j]);
                ++to[scc[j]];
            }
            if (i==j)
                ++sz[scc[i]];
        }
    if (sz[scc[1]]>1)
        dp[scc[1]]=-1;
    else
        dp[scc[1]]=1;
    //toposort
    for (int i=1;i<=cur;++i)
        if (to[i]==0)
            s.push(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        if (dp[x]!=0&&sz[x]>1)
            dp[x]=-1;
        for (int i : sccE[x])
        {
            if (--to[i]==0)
                s.push(i);
            if (dp[x]==0)
                continue;
            if (dp[i]==0)
                dp[i]=dp[x];
            else if (dp[x]==-1)
                dp[i]=-1;
            else if (dp[i]==1)
            {
                if (dp[x]==1)
                    dp[i]=2;
                else if (dp[x]==2)
                    dp[i]=2;
            }
        }
    }
    for (int i=1;i<=n;++i)
        cout<<dp[scc[i]]<<" ";
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}