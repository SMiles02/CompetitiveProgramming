#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;
int leaves[101];
int reg[101];
bool done[101];
vector<int> edges[101];

void dfs(int cur, int h)
{
    done[cur]=1;
    bool notLeaf=0;
    for (int x : edges[cur])
        if (!done[x])
        {
            notLeaf=1;
            dfs(x,h+1);
        }
    if (notLeaf)
        ++reg[h];
    else
        ++leaves[h];
}

ll sum(ll a, ll b)
{
    return (a+b)%mod;
}

ll mult(ll a, ll b)
{
    return (a*b)%mod;
}

ll dp[10001][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("tairos.in", "r", stdin);
    freopen("tairos.out", "w", stdout);
    int n,d,u,v;
    cin>>n;
    cin>>d;
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,0);
    dp[0][0]=1;
    for (int i=0;i<d;++i)
        for (int j=1;j<101&&i+j<=d;++j)
        {
            dp[i+j][0]=sum(dp[i+j][0],mult(dp[i][0],leaves[j]));
            dp[i+j][1]=sum(dp[i+j][1],mult(dp[i][0],reg[j]));
        }
    cout<<sum(dp[d][0],dp[d][1]);
    return 0;
}