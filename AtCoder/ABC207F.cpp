#include <bits/stdc++.h>
using namespace std;

const int N = 2005, MOD = 1e9+7;
int dp[N][4][N], tmp[4][N], sub[N];
vector<int> e[N];

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

int add(int a, int b, int c)
{
    return add(a,add(b,c));
}

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

void dfs(int c, int p)
{
    // 0 -> not covered at all
    // 1 -> guarding this node
    // 2 -> guarding neighbour, not chosen yet
    // 3 -> guarding neighbour, found neighbour
    dp[c][0][0] = 1;
    dp[c][1][1] = 1;
    dp[c][2][1] = 1;
    sub[c] = 1;
    for (int i : e[c])
        if (i != p)
        {
            dfs(i, c);
            for (int j=0;j<4;++j)
                for (int k=0;k<=sub[c];++k)
                    tmp[j][k] = dp[c][j][k];
            sub[c] += sub[i];
            for (int j=1;j<=sub[c];++j)
                for (int k=max(0,j-sub[c]+sub[i]);k<=min(sub[i],j);++k)
                {
                    // cout << dp[c][0][j] << " + " << tmp[0][j-k] << " * (" << dp[i][0][k] << " + " << dp[i][3][k] << ")\n";
                    dp[c][0][j]=add(dp[c][0][j],mul(tmp[0][j-k],add(dp[i][0][k],dp[i][3][k])));
                    dp[c][1][j]=add(dp[c][1][j],mul(tmp[1][j-k],add(dp[i][1][k],dp[i][2][k],dp[i][3][k])));
                    dp[c][2][j]=add(dp[c][2][j],mul(tmp[2][j-k],add(dp[i][0][k],dp[i][3][k])));
                    dp[c][3][j]=add(dp[c][3][j],mul(tmp[2][j-k],dp[i][1][k]),mul(tmp[3][j-k],add(dp[i][0][k],dp[i][1][k],dp[i][3][k])));
                }
        }
    cout<<c<<":\n";
    for (int i=0;i<4;++i)
    {
        for (int j=0;j<=sub[c];++j)
            cout<<dp[c][i][j]<<" ";
        cout<<"\n";
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
    for (int i=0;i<=n;++i)
        cout<<add(dp[1][0][i],add(dp[1][1][i],dp[1][3][i]))<<"\n";
    return 0;
}