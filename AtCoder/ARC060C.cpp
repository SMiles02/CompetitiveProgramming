#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

ll dp[51][51][3001];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,x,y;
    cin>>n>>x;
    dp[0][0][0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>y;
        for (int j=0;j<i;++j)
            for (int k=0;k<3000;++k)
                dp[i][j][k]=dp[i-1][j][k];
        for (int j=1;j<=i;++j)
            for (int k=y;k<3000;++k)
                dp[i][j][k]+=dp[i-1][j-1][k-y];
    }
    ll ans=0;
    for (int i=1;i*x<3000&&i<=n;++i)
        ans+=dp[n][i][i*x];
    cout<<ans;
    return 0;
}