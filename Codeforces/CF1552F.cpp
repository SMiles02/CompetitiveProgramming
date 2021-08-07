//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

const int MOD = 998244353;

int mul(int a, int b)
{
    return (1LL*a*b)%MOD;
}

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ct=0;
    ll ans=0;
    cin>>n;
    priority_queue<int> pq;
    array<int,3> a[n];
    for (int i=0;i<n;++i)
        for (int j=0;j<3;++j)
            cin>>a[i][j];
    for (int i=n-1;i>=0;--i)
    {
        while (!pq.empty()&&pq.top()>a[i][0])
            pq.pop();
        cout<<i<<": ";
        ans+=(a[i][0]-a[i][1])*a[i][2];
        cout<<(a[i][0]-a[i][1])*a[i][2]<<" ";
        ans+=2LL*(a[i][0]-a[i][1])*binpow(2,sz(pq));
        cout<<2LL*(a[i][0]-a[i][1])*sz(pq)<<"\n";
        if (a[i][2]||sz(pq))
            pq.push(a[i][1]);
    }
    ans+=a[n-1][0]+1;
    cout<<ans;
    return 0;
}