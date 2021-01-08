#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
#define f first
#define s second
using namespace std;

const int mn = 3003;
const ll INF = 1e15;
int sub[mn], b[mn], w[mn], n;
pii dp[mn][mn], dp2[mn];
vector<int> edges[mn];

//dp[i][j]
//i -> root node for this dp
//j -> how many villages made (not including topmost village)

pii add(pii a, pii b)
{
    return {a.f+b.f,a.s+b.s};
}

void dfs(int c, int p)
{
    sub[c]=1;
    dp[c][0]={0,w[c]-b[c]};
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c);
            sub[c]+=sub[i];
            for (int j=0;j<sub[c];++j)
                dp2[j]={0,-INF};
            for (int j=sub[c]-1;j+1;--j)
                for (int k=max(0,sub[i]+j-sub[c]-1);k<=min(sub[i],j);++k)
                {
                    //closing the below node (i)
                    if (j+1<=sub[c])
                    {
                        if (dp[i][k].s>0)
                            dp2[j+1]=max(dp2[j+1],{dp[c][j-k].f+dp[i][k].f+1,dp[c][j-k].s});
                        else
                            dp2[j+1]=max(dp2[j+1],{dp[c][j-k].f+dp[i][k].f,dp[c][j-k].s});
                    }
                    //merging it in
                    dp2[j]=max(dp2[j],add(dp[i][k],dp[c][j-k]));
                }
            for (int j=0;j<sub[c];++j)
                dp[c][j]=dp2[j];
        }
}

void solve()
{
    int m,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>b[i];
    for (int i=1;i<=n;++i)
    {
        cin>>w[i];
        edges[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<=n;++j)
            dp[i][j]={0,-INF};
    dfs(1,0);
    if (dp[1][m-1].s>0)
        cout<<dp[1][m-1].f+1<<"\n";
    else
        cout<<dp[1][m-1].f<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}