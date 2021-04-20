//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
using namespace std;

int dp[(1<<20)],lt[20],n,a,l,r,m,k,x,ans=21;
vector<int> v[20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("movie.in", "r", stdin);
    freopen("movie.out", "w", stdout);
    cin>>n>>a;
    for (int i=0;i<n;++i)
    {
        cin>>lt[i]>>k;
        v[i].push_back(k);
        while (k--)
        {
            cin>>x;
            v[i].push_back(x);
        }
    }
    for (int i=1;i<(1<<n);++i)
    {
        for (int j=0;j<n;++j)
            if (i&(1<<j))
            {
                if (dp[i^(1<<j)]<v[j][1]||v[j][v[j][0]]+lt[j]<dp[i^(1<<j)])
                    continue;
                l=1;r=v[j][0];
                while (l<r)
                {
                    m=l+(r-l)/2;
                    if (v[j][m]+lt[j]<dp[i^(1<<j)])
                        l=m+1;
                    else
                        r=m;
                }
                r=v[j][0];
                while (l<r)
                {
                    m=l+(r-l)/2+1;
                    if (v[j][m]<=dp[i^(1<<j)])
                        l=m;
                    else
                        r=m-1;
                }
                if (l!=r||dp[i^(1<<j)]<v[j][l]||v[j][l]+lt[j]<dp[i^(1<<j)])
                    continue;
                dp[i]=max(dp[i],v[j][l]+lt[j]);
            }
        if (dp[i]>=a)
            ans=min(ans,__builtin_popcount(i));
    }
    if (ans==21)
        ans=-1;
    cout<<ans;
    return 0;
}