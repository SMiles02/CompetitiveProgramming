#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a[1001][1001],x[1000001][2],y[1000001][2],dp[1002][1002];
bool bad[1000001],e[1000001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);
    int n,ans,used=0;
    cin>>n;
    ans=n*n;
    for (int i=1;i<=n*n;++i)
    {
        x[i][0]=1001;
        y[i][0]=1001;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            e[a[i][j]]=1;
            x[a[i][j]][0]=min(x[a[i][j]][0],i);
            x[a[i][j]][1]=max(x[a[i][j]][1],i);
            y[a[i][j]][0]=min(y[a[i][j]][0],j);
            y[a[i][j]][1]=max(y[a[i][j]][1],j);
        }
    }
    for (int i=1;i<=n*n;++i)
        if (e[i])
        {
            ++used;
            for (int j=x[i][0];j<=x[i][1];++j)
            {
                ++dp[j][y[i][0]];
                --dp[j][y[i][1]+1];
            }
        }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            dp[i][j]+=dp[i][j-1];
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (dp[i][j]>1)
                bad[a[i][j]]=1;
    for (int i=1;i<=n*n;++i)
        if (bad[i])
            --ans;
    if (used==1)
    {
        if (n==1)
            cout<<1;
        else
            cout<<n*n-1;
        return 0;
    }
    cout<<ans;
    return 0;
}