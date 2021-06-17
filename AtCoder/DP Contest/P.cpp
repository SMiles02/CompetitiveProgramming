#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+7, MOD = 1e9+7;
int dp[N][2];
vector<int> e[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

void dfs(int c, int p)
{
    dp[c][0]=dp[c][1]=1;
    for (int i : e[c])
        if (i!=p)
        {
            dfs(i,c);
            dp[c][0]=mul(dp[c][0],add(dp[i][0],dp[i][1]));
            dp[c][1]=mul(dp[c][1],dp[i][0]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    cout<<add(dp[1][0],dp[1][1]);
    return 0;
}