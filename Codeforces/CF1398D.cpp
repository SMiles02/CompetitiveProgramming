#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll dp[205][205][205];

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int R,G,B,k;
    cin>>R>>G>>B;
    int r[R],g[G],b[B];
    for (int i=1;i<=R;++i)
        cin>>r[i];
    for (int i=1;i<=G;++i)
        cin>>g[i];
    for (int i=1;i<=B;++i)
        cin>>b[i];
    sort(r+1,r+R+1);
    sort(g+1,g+G+1);
    sort(b+1,b+B+1);
    for (int z=1;z<=R+G+B;++z)
        for (int i=0;i<=R;++i)
            for (int j=0;j<=G;++j)
            {
                k=z-i-j;
                //cout<<i<<" "<<j<<" "<<k<<"\n";
                if (0<=k&&k<=B)
                {
                    if (i&&j)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+r[i]*g[j]);
                    if (i&&k)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+r[i]*b[k]);
                    if (k&&j)
                        dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+g[j]*b[k]);
                    //cout<<i<<","<<j<<","<<k<<" = "<<dp[i][j][k]<<"\n";
                }
            }
    cout<<dp[R][G][B];
    return 0;
}