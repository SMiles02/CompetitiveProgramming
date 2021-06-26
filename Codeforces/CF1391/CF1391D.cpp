#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string s[1000000];
int dp[1000000][8];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    if (n>3&&m>3)
    {
        cout<<-1;
        return 0;
    }
    if (n==1||m==1)
    {
        cout<<0;
        return 0;
    }
    if (n==2)
    {
        for (int i=0;i<3;++i)
            dp[0][i]=abs(i-((s[0][0]-'0')+(s[1][0]-'0')));
        for (int j=1;j<m;++j)
        {
            for (int i=0;i<3;++i)
                dp[j][i]=abs(i-((s[0][j]-'0')+(s[1][j]-'0')));
            dp[j][0]+=dp[j-1][1];
            dp[j][2]+=dp[j-1][1];
            dp[j][1]+=min(dp[j-1][0],dp[j-1][2]);
        }
        cout<<min(min(dp[m-1][0],dp[m-1][1]),dp[m-1][2]);
        return 0;
    }
    if (m==2)
    {
        for (int i=0;i<3;++i)
            dp[0][i]=abs(i-((s[0][0]-'0')+(s[0][1]-'0')));
        for (int j=1;j<n;++j)
        {
            for (int i=0;i<3;++i)
                dp[j][i]=abs(i-((s[j][0]-'0')+(s[j][1]-'0')));
            dp[j][0]+=dp[j-1][1];
            dp[j][2]+=dp[j-1][1];
            dp[j][1]+=min(dp[j-1][0],dp[j-1][2]);
        }
        cout<<min(min(dp[m-1][0],dp[m-1][1]),dp[m-1][2]);
        return 0;
    }
    if (n==3)
    {
        x=(s[0][0]-'0')*4+(s[1][0]-'0')*2+(s[2][0]-'0');
        for (int i=0;i<8;++i)
            dp[i][0]=__builtin_popcount(i^x);
        for (int j=1;j<m;++j)
        {
            x=(s[0][j]-'0')*4+(s[1][j]-'0')*2+(s[2][j]-'0');
            for (int i=0;i<8;++i)
                dp[i][j]=__builtin_popcount(i^x);
            dp[0][j]+=min(dp[2][j-1],dp[5][j-1]);
            dp[1][j]+=min(dp[3][j-1],dp[4][j-1]);
            dp[2][j]+=min(dp[0][j-1],dp[7][j-1]);
            dp[3][j]+=min(dp[1][j-1],dp[6][j-1]);
            dp[7][j]+=min(dp[2][j-1],dp[5][j-1]);
            dp[6][j]+=min(dp[3][j-1],dp[4][j-1]);
            dp[5][j]+=min(dp[0][j-1],dp[7][j-1]);
            dp[4][j]+=min(dp[1][j-1],dp[6][j-1]);
        }
    }
    else
    {
        x=(s[0][0]-'0')*4+(s[0][1]-'0')*2+(s[0][2]-'0');
        for (int i=0;i<8;++i)
            dp[i][0]=__builtin_popcount(i^x);
        for (int j=1;j<m;++j)
        {
            x=(s[j][0]-'0')*4+(s[j][1]-'0')*2+(s[j][2]-'0');
            for (int i=0;i<8;++i)
                dp[i][j]=__builtin_popcount(i^x);
            dp[0][j]+=min(dp[2][j-1],dp[5][j-1]);
            dp[1][j]+=min(dp[3][j-1],dp[4][j-1]);
            dp[2][j]+=min(dp[0][j-1],dp[7][j-1]);
            dp[3][j]+=min(dp[1][j-1],dp[6][j-1]);
            dp[7][j]+=min(dp[2][j-1],dp[5][j-1]);
            dp[6][j]+=min(dp[3][j-1],dp[4][j-1]);
            dp[5][j]+=min(dp[0][j-1],dp[7][j-1]);
            dp[4][j]+=min(dp[1][j-1],dp[6][j-1]);
        }
    }
    cout<<min(min(min(dp[0][m-1],dp[1][m-1]),min(dp[2][m-1],dp[3][m-1])),min(min(dp[4][m-1],dp[5][m-1]),min(dp[6][m-1],dp[7][m-1])));
    return 0;
}