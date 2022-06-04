#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 1e5+1, INF = 1e9;
int x,f[maxn],dp[maxn],ans=INF;
vector<int> edges[maxn];
bitset<maxn> done;

void dfs(int c)
{
    ++x;
    done[c]=1;
    for (int i : edges[c])
        if (!done[i])
            dfs(i);
}

void allLucky(int k)
{
    if (k>=maxn)
        return;
    ans=min(ans,dp[k]);
    allLucky(k*10+4);
    allLucky(k*10+7);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
        {
            x=0;
            dfs(i);
            ++f[x];
        }
    for (int i=1;i<maxn;++i)
        dp[i]=INF;
    dp[0]=0;
    for (int i=1;i<=n;++i)
        if (f[i])
        {
            for (int j=0;(1<<j)<f[i];++j)
            {
                for (int k=n;k-((1<<j)*i)>=0;--k)
                    dp[k]=min(dp[k],dp[k-((1<<j)*i)]+(1<<j));
                f[i]-=(1<<j);
            }
            for (int k=n;k-(f[i]*i)>=0;--k)
                dp[k]=min(dp[k],dp[k-(f[i]*i)]+f[i]);
        }
    allLucky(4);
    allLucky(7);
    if (ans==INF)
        cout<<-1;
    else
        cout<<ans-1;
    return 0;
}