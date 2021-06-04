#include <bits/stdc++.h>
using namespace std;

int dp[3000][3000][2];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    long long ans=0;
    string s[n];
    for (int i=0;i<n;++i)
        cin>>s[i];
    for (int i=n-2;i>=0;--i)
        for (int j=m-1;j>=0;--j)
            dp[i][j][0]=dp[i+1][j][0]+(s[i+1][j]=='I');
    for (int j=m-2;j>=0;--j)
        for (int i=n-1;i>=0;--i)
            dp[i][j][1]=dp[i][j+1][1]+(s[i][j+1]=='O');
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            if (s[i][j]=='J')
                ans+=dp[i][j][0]*dp[i][j][1];
    cout<<ans;
    return 0;
}