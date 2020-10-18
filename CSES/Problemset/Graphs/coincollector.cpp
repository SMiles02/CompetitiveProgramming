#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int maxn = 1e5 + 7;
vector<int> e1[maxn], e2[maxn], from[maxn];
bitset<maxn> done;
int coins[maxn], comp[maxn], to[maxn];
ll dp[maxn], sum[maxn];
stack<int> s;
 
ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}
 
void dfs1(int c)
{
    done[c]=1;
    for (int i : e1[c])
        if (!done[i])
            dfs1(i);
    s.push(c);
}
 
void dfs2(int c, int k)
{
    comp[c]=k;
    sum[k]+=coins[c];
    for (int i : e2[c])
        if (!comp[i])
            dfs2(i,k);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,k=0;
    ll ans=0;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>coins[i];
    while (m--)
    {
        cin>>u>>v;
        e1[u].push_back(v);
        e2[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
            dfs1(i);
    while (!s.empty())
    {
        if (comp[s.top()])
        {
            s.pop();
            continue;
        }
        dfs2(s.top(),++k);
        s.pop();
        dp[k]=sum[k];
    }
    for (int i=1;i<=n;++i)
        for (int j : e1[i])
            if (comp[i]!=comp[j])
            {
                from[comp[i]].push_back(comp[j]);
                ++to[comp[j]];
            }
    for (int i=1;i<=k;++i)
        if (!to[i])
            s.push(i);
    while (!s.empty())
    {
        v=s.top();
        s.pop();
        ans=max(ans,dp[v]);
        for (int i : from[v])
        {
            dp[i]=max(dp[i],sum[i]+dp[v]);
            --to[i];
            if (to[i]==0)
                s.push(i);
        }
    }
    cout<<ans;
    return 0;
}