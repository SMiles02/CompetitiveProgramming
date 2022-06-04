#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2];

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    for (int i=0;i<10;++i)
        for (int j=0;j<2;++j)
            for (int k=0;k<2;++k)
                dp[i][j][k]=0;
    dp[n][0][0]=1;
    for (int i=n-1;i>=0;--i)
        for (int j=0;j<10;++j)
            for (int k=0;k<10;++k)
                for (int l=0;l<2;++l)
                    for (int m=0;m<2;++m)
                        if ((j+k+l)%10==s[i]-'0')
                            dp[i][m][(j+k+l)/10]+=dp[i+1][l][m];
    cout<<dp[0][0][0]-2<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}