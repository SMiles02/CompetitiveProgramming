#include <bits/stdc++.h>
using namespace std;

bitset<(1<<5)> dp[4];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=1,r=1e9,m,c;
    cin>>n;
    int a[n][5];
    for (int i=0;i<n;++i)
        for (int j=0;j<5;++j)
            cin>>a[i][j];
    dp[0][0]=1;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        for (int i=1;i<4;++i)
            dp[i].reset();
        for (int i=0;i<n;++i)
        {
            c=0;
            for (int j=0;j<5;++j)
                if (a[i][j]>=m)
                    c^=(1<<j);
            for (int j=1;j<4;++j)
            {
                for (int k=(1<<5)-1;k>=0;--k)
                {
                    if ((k&c)==c)
                        dp[j][k]=dp[j-1][k^c]|dp[j][k];
                    for (int l=0;l<5;++l)
                        if (((1<<l)&k)==0)
                            dp[j][k]=dp[j][k]|dp[j][k^(1<<l)];
                }
            }
        }
        if (dp[3][(1<<5)-1])
            l=m;
        else
            r=m-1;
    }
    cout<<l;
    return 0;
}