#include <bits/stdc++.h>
using namespace std;

const int N = 505, K = 5005;
bitset<N> dp[2][N], sea[N];
char c[N][N];
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>c[i][j];
            dp[0][i][j]=sea[i][j]=(c[i][j]=='.');
        }
    cin>>s;
    for (auto x : s)
    {
        if (x=='N')
            for (int i=1;i<=n;++i)
                dp[1][i]=dp[0][i+1]&sea[i];
        else if (x=='S')
            for (int i=1;i<=n;++i)
                dp[1][i]=dp[0][i-1]&sea[i];
        else if (x=='E')
            for (int i=1;i<=n;++i)
                dp[1][i]=(dp[0][i]<<1)&sea[i];
        else if (x=='W')
            for (int i=1;i<=n;++i)
                dp[1][i]=(dp[0][i]>>1)&sea[i];
        else
            for (int i=1;i<=n;++i)
                dp[1][i]=(dp[0][i+1]|dp[0][i-1]|(dp[0][i]>>1)|(dp[0][i]<<1))&sea[i];
        for (int i=1;i<=n;++i)
            dp[0][i]=dp[1][i];
    }
    int ans = 0;
    for (int i=1;i<=n;++i)
        ans+=dp[0][i].count();
    cout<<ans;
    return 0;
}