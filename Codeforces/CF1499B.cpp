#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[110][2][2];

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<2;++j)
            for (int k=0;k<2;++k)
                dp[i+1][j][k]=0;
        for (int j=0;j<=(s[i]-'0');++j)
            for (int k=0;k<2;++k)
                if (dp[i][j][k])
                    dp[i+1][(s[i]-'0')][0]=1;
        for (int j=0;j<2;++j)
            if (dp[i][j][0])
                dp[i+1][j][1]=1;
    }
    for (int j=0;j<2;++j)
        for (int k=0;k<2;++k)
            if (dp[n][j][k])
            {
                cout<<"YES\n";
                return;
            }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dp[0][0][0]=1;
    while (n--)
        solve();
    return 0;
}