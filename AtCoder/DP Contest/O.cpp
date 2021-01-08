#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int dp[22][(1<<22)];

void add(int& x, int& y)
{
    x+=y;
    if (x>=mod)
        x-=mod;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    dp[0][0]=1;
    int a[n];
    for (int i=1;i<=n;++i)
    {
        for (int j=0;j<n;++j)
            cin>>a[j];
        for (int j=0;j<(1<<n);++j)
            if (__builtin_popcount(j)==i)
                for (int k=0;k<n;++k)
                    if (((1<<k)&j)&&a[k])
                        add(dp[i][j],dp[i-1][j-(1<<k)]);
    }
    cout<<dp[n][(1<<n)-1];
    return 0;
}