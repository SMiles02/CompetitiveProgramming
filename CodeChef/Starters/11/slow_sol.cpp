//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

const int MOD = 1e9+7, N = 1e5;

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}

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
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res;
}

int dv(int a, int b)
{
    return mul(a,binpow(b,MOD-2));
}

int sub(int a, int b)
{
    return add(a,MOD-b);
}

int dp[11][N+1];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int b[n];
    for (int i=1;i<n;++i)
        cin>>b[i];
    for (int i=0;i<=N;++i)
        dp[0][i]=1;
    for (int i=1;i<n;++i)
    {
        dp[i][b[i]]=dp[i-1][b[i]];
        for (int j=b[i]+1;j<=N;++j)
        {
            dp[i][b[i]]=add(dp[i][b[i]],dp[i-1][j]);
            dp[i][j]=add(dp[i][j],dp[i-1][b[i]]);
        }
    }
    int ans=0;
    for (int i=0;i<=N;++i)
        ans=add(ans,dp[n-1][i]);
    cout<<ans;
    return 0;
}