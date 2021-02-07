#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+9;
int dp[11][1001][1001];

int add(int a, int b)
{
    a+=b;
    if (a>=mod)
        a-=mod;
    return a;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    int n,m,x;
    cin>>n>>m>>x;
    int a[n+1],b[m+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int j=1;j<=m;++j)
        cin>>b[j];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for (int i=0;i<=n;++i)
        for (int j=0;j<=m;++j)
            dp[0][i][j]=1;
    for (int k=1;k<=x;++k)
        for (int i=1;i<=n;++i)
            for (int j=1;j<=m;++j)
            {
                if (a[i]<=b[j])
                    dp[k][i][j]=add(add(dp[k][i-1][j],dp[k][i][j-1]),add(-dp[k][i-1][j-1],mod));
                else
                    dp[k][i][j]=add(add(add(dp[k-1][i-1][j-1],dp[k][i-1][j]),dp[k][i][j-1]),add(-dp[k][i-1][j-1],mod));
            }
    cout<<dp[x][n][m];
	return 0;
}