//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int M = 512;
bitset<M> dp[M];
// dp[mx][xor]
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    dp[0][0]=1;
    for (int i=0;i<n;++i)
    {
        cin>>k;
        dp[k][k]=1;
        for (int j=1;j<M;++j)
            dp[j] |= dp[j-1];
        if (k>0)
            for (int j=0;j<M;++j)
                dp[k][j] = dp[k][j] | dp[k-1][j^k];
    }
    for (int i=1;i<M;++i)
        dp[i] |= dp[i-1];
    cout<<dp[M-1].count()<<"\n";
    for (int i=0;i<M;++i)
        if (dp[M-1][i])
            cout<<i<<" ";
    return 0;
}