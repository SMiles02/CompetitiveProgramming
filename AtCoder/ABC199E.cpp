#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<array<int,2>> c[19];
ll dp[19][(1<<18)];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y,z;
    bool ok;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y>>z;
        c[x].push_back({y,z});
    }
    dp[0][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=0;j<(1<<n);++j)
            if (__builtin_popcount(j)==i)
            {
                ok=1;
                for (auto k : c[i])
                    if (__builtin_popcount(j&((1<<k[0])-1))>k[1])
                        ok=0;
                if (ok)
                    for (int k=0;k<n;++k)
                        if ((1<<k)&j)
                            dp[i][j]+=dp[i-1][j^(1<<k)];
            }
    cout<<dp[n][(1<<n)-1];
    return 0;
}