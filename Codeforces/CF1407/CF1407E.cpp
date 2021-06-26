#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn=500000+7, INF=1e9;
int d[maxn][2],dp[maxn];
bool col[maxn];
vector<pii> to[maxn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,u,v,t;
    cin>>n>>m;
    for (int i=0;i<m;++i)
    {
        cin>>u>>v>>t;
        to[v].push_back({u,t});
    }
    for (int i=1;i<n;++i)
    {
        d[i][0]=INF;
        d[i][1]=INF;
        dp[i]=INF;
    }
    d[n][0]=0;
    d[n][1]=0;
    dp[n]=0;
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        v=q.front();
        q.pop();
        if (d[v][0]<d[v][1])
            col[v]=1;
        for (pii i : to[v])
        {
            d[i.f][i.s]=min(d[i.f][i.s],dp[v]+1);
            if (dp[i.f]==INF&&d[i.f][i.s]<INF&&d[i.f][i.s^1]<INF)
                q.push(i.f);
            dp[i.f]=max(d[i.f][i.s],d[i.f][i.s^1]);
        }
    }
    for (int i=1;i<n;++i)
        if (d[i][0]<d[i][1])
            col[i]=1;
    if (dp[1]==INF)
        cout<<"-1\n";
    else
        cout<<dp[1]<<"\n";
    for (int i=1;i<=n;++i)
        cout<<col[i];
    return 0;
}