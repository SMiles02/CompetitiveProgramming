#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

bitset<505> dp[1005][2];

void solve()
{
    string s,t;
    cin>>s;
    cin>>t;
    int n=sz(s),m=sz(t);
    for (int i=1;i<1005;++i)
        for (int j=0;j<2;++j)
            dp[i][j].reset();
    for (int i=0;i<m;++i)
        for (int j=0;j<n;++j)
        {
            dp[i+1][0][j+1]=((s[j]==t[i])&(dp[i][0][j]));
            dp[i+1][1][j+1]=((s[j]==t[i])&(dp[i][0][j+2]|dp[i][1][j+2]));
        }
    if (dp[m][0].count()+dp[m][1].count())
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=0;i<505;++i)
        dp[0][0][i]=1;
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}