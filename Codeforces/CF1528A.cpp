#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
int a[N][2];
long long dp[N][2];
vector<int> e[N];

void dfs(int c, int p)
{
    dp[c][0]=dp[c][1]=0;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            dp[c][0]+=max(dp[i][0]+abs(a[c][0]-a[i][0]),dp[i][1]+abs(a[c][0]-a[i][1]));
            dp[c][1]+=max(dp[i][0]+abs(a[c][1]-a[i][0]),dp[i][1]+abs(a[c][1]-a[i][1]));
        }
}

void solve()
{
    int n,x,y;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        e[i].clear();
        cin>>a[i][0]>>a[i][1];
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1])<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}