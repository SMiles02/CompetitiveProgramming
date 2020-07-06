#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,a,b,c,d;
    cin>>n>>q;
    string s;
    for (int i=1;i<=n;++i)
    {
        cin>>s;
        for (int j=1;j<=n;++j)
            if (s[j-1]=='.')
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+1;
    }
    while (q--)
    {
        cin>>a>>b>>c>>d;
        cout<<dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1]<<"\n";
    }
    return 0;
}