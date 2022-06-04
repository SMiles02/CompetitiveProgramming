#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,u,v;
vector<int> edges[100001];
int a[3][100001];
ll ans[6][100002];

ll mini(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

void dfs(int cur, int last, vector<int> order, int clr, int k)
{
    ans[k][cur]=order[clr]+1;
    ans[k][n+1]+=a[order[clr]][cur];
    for (int x : edges[cur])
        if (x!=last)
            dfs(x,cur,order,(clr+1)%3,k);
}

void printer(int k)
{
    cout<<ans[k][n+1]<<"\n";
    for (int i=1;i<=n;++i)
        cout<<ans[k][i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=0;i<3;++i)
        for (int j=1;j<=n;++j)
            cin>>a[i][j];
    for (int i=1;i<n;++i)
    {
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
        if (sz(edges[i])>2)
        {
            cout<<-1;
            return 0;
        }
    for (int i=1;i<=n;++i)
        if (sz(edges[i])==1)
        {
            v=i;
            break;
        }
    dfs(v,0,{0,1,2},0,0);
    dfs(v,0,{0,2,1},0,1);
    dfs(v,0,{1,0,2},0,2);
    dfs(v,0,{1,2,0},0,3);
    dfs(v,0,{2,0,1},0,4);
    dfs(v,0,{2,1,0},0,5);
    ll mini=1e18;
    for (int i=0;i<6;++i)
        mini=min(mini,ans[i][n+1]);
    for (int i=0;i<6;++i)
        if (ans[i][n+1]==mini)
        {
            printer(i);
            return 0;
        }
    return 0;
}