#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1502;
bitset<mn> blocks[mn], lit[mn], dpU[mn], dpD[mn], dpL[mn], dpR[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,w,n,m,x,y;
    cin>>h>>w>>n>>m;
    while (n--)
    {
        cin>>x>>y;
        dpD[x][y]=1;
        dpR[x][y]=1;
        dpU[x][y]=1;
        dpL[x][y]=1;
    }
    while (m--)
    {
        cin>>x>>y;
        blocks[x][y]=1;
    }
    for (int i=1;i<=h;++i)
        for (int j=1;j<=w;++j)
            if (!blocks[i][j])
            {
                if (dpD[i-1][j])
                    dpD[i][j]=1;
                if (dpD[i][j])
                    lit[i][j]=1;
            }
    for (int i=1;i<=h;++i)
        for (int j=1;j<=w;++j)
            if (!blocks[i][j])
            {
                if (dpR[i][j-1])
                    dpR[i][j]=1;
                if (dpR[i][j])
                    lit[i][j]=1;
            }
    for (int i=h;i;--i)
        for (int j=w;j;--j)
            if (!blocks[i][j])
            {
                if (dpU[i][j+1])
                    dpU[i][j]=1;
                if (dpU[i][j])
                    lit[i][j]=1;
            }
    for (int i=h;i;--i)
        for (int j=w;j;--j)
            if (!blocks[i][j])
            {
                if (dpL[i+1][j])
                    dpL[i][j]=1;
                if (dpL[i][j])
                    lit[i][j]=1;
            }
    int ans=0;
    for (int i=1;i<=h;++i)
        ans+=lit[i].count();
    cout<<ans;
    return 0;
}