#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2001, mod = 1e9+7;
int a[mn];
ll ft[mn],dp[mn][mn];
map<vector<int>,int> m;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

ll mult(ll a, ll b)
{
    return (a*b)%mod;
}

ll C(int n, int k)
{
    return mult(ft[n],binpow(mult(ft[k],ft[n-k]),mod-2));
}

ll calc(ll n)
{
    return mult(mult(n,n-1),(mod+1)/2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,K,x=0;
    cin>>n>>K;
    string s;
    dp[0][0]=1;
    ft[0]=1;
    for (int i=0;i<n;++i)
    {
        ft[i+1]=(ft[i]*(i+1))%mod;
        vector<int> f(26,0);
        cin>>s;
        for (auto j : s)
            ++f[j-'a'];
        if (!m[f])
            m[f]=++x;
        ++a[m[f]];
    }
    for (int i=1;i<=x;++i)
        for (int j=0;j<=K;++j)
            for (int k=0;k<=a[i]&&calc(k)<=j;++k)
                dp[i][j]=(dp[i][j]+mult(dp[i-1][j-calc(k)],C(a[i],k)))%mod;
    cout<<dp[x][K];
    return 0;
}