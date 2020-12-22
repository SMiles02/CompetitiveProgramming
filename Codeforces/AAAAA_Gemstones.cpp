#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int mn = 405;
int p[3][3][mn][mn],dp[2][mn][mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a[mn][mn],ans,cur,c;
    cin>>n;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=i;++j)
        {
            cin>>a[i][j];
            --a[i][j];
            for (int k=0;k<3;++k)
                ++p[k][a[i][j]][i][j];
            for (int k=0;k<3;++k)
                p[0][k][i][j]+=p[0][k][i-1][j];
            for (int k=0;k<3;++k)
                p[1][k][i][j]+=p[1][k][i][j-1];
            for (int k=0;k<3;++k)
                p[2][k][i][j]+=p[2][k][i-1][j-1];
        }
    for (int d=1;d<n;++d)
    {
        for (int a=1;a+d<=n;++a)
        {
            for (int b=1;b+d<=n;++b)
            {
                c=b+d;cur=0;ans=0;
                for (int i=0;i<3;++i)
                    cur=max(cur,p[0][i][c][a]-p[0][i][b-1][a]);
                ans=max(ans,cur+dp[0][a+1][b+1]);
                cur=0;
                for (int i=0;i<3;++i)
                    cur=max(cur,p[1][i][c][a-b+c]-p[1][i][c][a-1]);
                ans=max(ans,cur+dp[0][a][b]);
                cur=0;
                for (int i=0;i<3;++i)
                    cur=max(cur,p[2][i][c][a-b+c]-p[2][i][b-1][a-1]);
                ans=max(ans,cur+dp[0][a][b+1]);
                dp[1][a][b]=ans;
            }
        }
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                dp[0][i][j]=dp[1][i][j];
    }
    cout<<dp[0][1][1];
    return 0;
}