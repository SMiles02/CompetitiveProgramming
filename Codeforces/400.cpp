#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mod = 1e9+7;

int toInt(string s)
{
    int r = 0;
    for (auto i : s)
    {
        r*=2;
        if (i=='1')
            ++r;
    }
    return r;
}

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

const int mn = (1<<10);
vector<int> to[mn];
ll dp[10001][mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,K,p,q;
    cin>>n>>x>>K;
    string s,t;
    cin>>s;
    cin>>t;
    p=toInt(s);
    q=toInt(t);
    for (int i=0;i<(1<<n);++i)
        for (int j=0;j<(1<<n);++j)
            if (__builtin_popcount(i^j)==x)
                to[i].push_back(j);
    dp[0][p]=1;
    ll P = 1, Q = 1;
    for (int i=1;i<=x;++i)
        P*=i;
    for (int i=1;i<=n-x;++i)
        P*=i;
    for (int i=1;i<=n;++i)
        Q*=i;
    P = (P*binpow(Q,mod-2))%mod;
    for (int i=1;i<=K;++i)
    {
        //cout<<i<<":\n";
        for (int j=0;j<(1<<n);++j)
        {
            for (int k : to[j])
            {
                dp[i][j]+=(dp[i-1][k]*P);
                dp[i][j]%=mod;
            }
            //cout<<j<<": "<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[K][q];
    return 0;
}