#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int dp[2][4][4][4][4];

int unique(int x, int y, int z)
{
    int ans=0;
    bool b;
    b=0;
    for (int i : {x,y,z})
        if (i==1)
            b=1;
    ans+=b;
    b=0;
    for (int i : {x,y,z})
        if (i==2)
            b=1;
    ans+=b;
    b=0;
    for (int i : {x,y,z})
        if (i==3)
            b=1;
    ans+=b;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,INF=-1e9,c,ans;
    string s;
    cin>>n;
    cin>>s;
    for (int i=0;i<4;++i)
        for (int j=0;j<4;++j)
            for (int k=0;k<4;++k)
                for (int l=0;l<4;++l)
                    dp[0][i][j][k][l]=INF;
    dp[0][0][0][0][0]=0;
    for (int z=0;z<n;++z)
    {
        if (s[z]=='M')
            c=1;
        else if (s[z]=='B')
            c=2;
        else
            c=3;
        for (int i=0;i<4;++i)
            for (int j=0;j<4;++j)
                for (int k=0;k<4;++k)
                    for (int l=0;l<4;++l)
                        dp[1][i][j][k][l]=INF;
        for (int i=0;i<4;++i)
            for (int j=0;j<4;++j)
                for (int k=0;k<4;++k)
                    for (int l=0;l<4;++l)
                    {
                        dp[1][i][c][j][k]=max(dp[1][i][c][j][k],dp[0][l][i][j][k]+unique(l,i,c));
                        dp[1][i][j][k][c]=max(dp[1][i][j][k][c],dp[0][i][j][l][k]+unique(l,k,c));
                    }
        for (int i=0;i<4;++i)
            for (int j=0;j<4;++j)
                for (int k=0;k<4;++k)
                    for (int l=0;l<4;++l)
                        swap(dp[0][i][j][k][l],dp[1][i][j][k][l]);
    }
    ans=0;
    for (int i=0;i<4;++i)
            for (int j=0;j<4;++j)
                for (int k=0;k<4;++k)
                    for (int l=0;l<4;++l)
                        ans=max(ans,dp[0][i][j][k][l]);
    cout<<ans;
    return 0;
}