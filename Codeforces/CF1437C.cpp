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

const int INF = 1e9;
int dp[401][201],a[200];
//time,done,

void solve()
{
    int n;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<401;++i)
    {
        dp[i][0]=0;
        for (int j=1;j<201;++j)
            dp[i][j]=INF;
    }
    for (int i=1;i<401;++i)
        for (int j=1;j<=n;++j)
            dp[i][j]=min(min(dp[i-1][j-1]+abs(a[j-1]-i),dp[i-1][j]),dp[i][j]);
    cout<<dp[400][n]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}