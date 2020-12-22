#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[200001][2];
vector<int> edges[200001];

void dfs(int c, int p)
{
    int t=0;
    for (int i : edges[c])
        if (i!=p)
        {
            dfs(i,c);
            dp[c][1]=max(dp[c][1],dp[i][0]+1);
            t+=dp[i][1];
        }
    dp[c][0]=t;
    for (int i : edges[c])
        if (i!=p)
            dp[c][1]=max(dp[c][1],t+dp[i][0]+1-dp[i][1]);
    //cout<<c<<" "<<dp[c][0]<<" "<<dp[c][1]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(1,0);
    cout<<max(dp[1][0],dp[1][1]);
    return 0;
}