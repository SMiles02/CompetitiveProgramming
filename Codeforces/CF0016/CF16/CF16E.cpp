#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double dp[(1<<19)];

int f(int a)
{
    return (a*(a-1))/2;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    double p[n][n];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            cin>>p[i][j];
    dp[(1<<n)-1]=1;
    for (int i=(1<<n)-1;i;--i)
        for (int j=0;j<n;++j)
            if ((1<<j)&i)
                for (int k=0;k<n;++k)
                    if ((1<<k)&(i-(1<<j)))
                        dp[i-(1<<j)]+=((dp[i]*p[k][j])/f(__builtin_popcount(i)));
    for (int i=0;i<n;++i)
        cout<<fixed<<setprecision(8)<<dp[(1<<i)]<<" ";
    return 0;
}